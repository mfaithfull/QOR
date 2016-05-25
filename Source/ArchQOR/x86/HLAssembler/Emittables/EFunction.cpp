//EFunction.cpp

// Copyright (c) 2008-2010, Petr Kobalicek <kobalicek.petr@gmail.com>
// Copyright (c) Querysoft Limited 2012
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#include "ArchQOR.h"

#if		( QOR_ARCH == QOR_ARCH_X86_32 || QOR_ARCH == QOR_ARCH_X86_64 )

#include <new>
#include "ArchQOR/x86/HLAssembler/Emittables/EFunction.h"
#include "ArchQOR/x86/HLAssembler/x86HLAContext.h"
#include "ArchQOR/x86/CPUInfo.h"
#include "ArchQOR/x86/Assembler/BatchCPU/x86CPUCore.h"
#include <assert.h>

//------------------------------------------------------------------------------
namespace nsArch
{
	//------------------------------------------------------------------------------
	namespace nsx86
	{
		//------------------------------------------------------------------------------
		CEFunction::CEFunction( nsArch::CHighLevelAssemblerBase* c ) __QCMP_THROW : CEmittable( c, EMITTABLE_FUNCTION )
		{
			m_paArgumentVariables = 0;
			nsCodeQOR::memset32( m_auiHints, static_cast< Cmp_unsigned__int32 >( INVALID_VALUE ), __QCS_ARRAY_SIZE( m_auiHints ) );
			
			m_bIsStackAlignedByOsTo16Bytes = CompilerUtil::isStack16ByteAligned();		// Stack is always aligned to 16-bytes when using 64-bit OS.
			m_bIsStackAlignedByFnTo16Bytes = false;										// Manual aligning is autodetected by prepare() method.

			// Clear to safe defaults.
			m_bIsNaked = false;
			m_bIsEspAdjusted = false;
			m_bIsCaller = false;
			m_bPePushPop = true;
			m_bEmitEMMS = false;
			m_bEmitSFence = false;
			m_bEmitLFence = false;
			m_bFinished = false;

			m_uiModifiedAndPreservedGP = 0;
			m_uiModifiedAndPreservedMM = 0;
			m_uiModifiedAndPreservedXMM = 0;
			m_iPePushPopStackSize = 0;
			m_iPeMovStackSize = 0;
			m_iPeAdjustStackSize = 0;
			m_iMemStackSize = 0;
			m_iMemStackSize16 = 0;
			m_iFunctionCallStackSize = 0;

			Cx86HLAssembler* px86HLA = dynamic_cast< Cx86HLAssembler* >( c );
			m_EntryLabel = px86HLA->newLabel();
			m_ExitLabel = px86HLA->newLabel();

			m_pProlog = HLA_newObject< CEProlog >( c, this );
			m_pEpilog = HLA_newObject< CEEpilog >( c, this );
			m_pEnd = HLA_newObject< CEFunctionEnd >( c );
		}

		//------------------------------------------------------------------------------
		CEFunction::~CEFunction() __QCMP_THROW
		{
		}

		//------------------------------------------------------------------------------
		void CEFunction::prepare( CHLAssemblerContextBase& cc) __QCMP_THROW
		{
			m_uiOffset = cc.IncrementCurrentOffset();
		}

		//------------------------------------------------------------------------------
		int CEFunction::getMaxSize() const __QCMP_THROW
		{
			return 0;			// CEFunction is NOP.
		}

		//------------------------------------------------------------------------------
		void CEFunction::setPrototype( Cmp_unsigned__int32 callingConvention, const Cmp_unsigned__int32* arguments, Cmp_unsigned__int32 argumentsCount, Cmp_unsigned__int32 returnValue ) __QCMP_THROW
		{
			m_FunctionPrototype.setPrototype( callingConvention, arguments, argumentsCount, returnValue );
		}

		//------------------------------------------------------------------------------
		void CEFunction::setHint( Cmp_unsigned__int32 hint, Cmp_unsigned__int32 value ) __QCMP_THROW
		{
			assert( hint < __QCS_ARRAY_SIZE( m_auiHints ) );
			m_auiHints[ hint ] = value;
		}

		//------------------------------------------------------------------------------
		void CEFunction::_createVariables() __QCMP_THROW
		{
			Cmp_unsigned__int32 i, count = m_FunctionPrototype.getArgumentsCount();
			if( count == 0 ) 
			{
				return;
			}

			m_paArgumentVariables = reinterpret_cast<VarData**>( ( dynamic_cast< CHighLevelAssemblerBase* >( m_pHLAssembler ) )->getZone().zalloc( count * sizeof( VarData* ) ) );
			if( m_paArgumentVariables == 0 )
			{
				( dynamic_cast< Cx86HLAssembler* >( m_pHLAssembler ) )->setError( ERROR_NO_HEAP_MEMORY );
				return;
			}

			char argNameStorage[ 64 ];
			char* argName = 0;

			bool debug = ( dynamic_cast< CHighLevelAssemblerBase* >( m_pHLAssembler ) )->getLogger() != 0;
			if( debug ) 
			{
				argName = argNameStorage;
			}

			for( i = 0; i < count; i++ )
			{
				CFunctionPrototype::Argument& a = m_FunctionPrototype.getArguments()[ i ];
				if( debug ) 
				{
					//TODO:snprintf(argName, __QCS_ARRAY_SIZE(argNameStorage), "arg_%u", i);
				}

				Cmp_unsigned__int32 size = getVariableSize( a.variableType );
				VarData* vdata = ( dynamic_cast< Cx86HLAssembler* >( m_pHLAssembler ) )->_newVarData( argName, a.variableType, size );

				if( a.registerIndex != (Cmp_unsigned__int32)INVALID_VALUE )
				{
					vdata->isRegArgument = true;
					vdata->registerIndex = a.registerIndex;
				}

				if( a.stackOffset != (Cmp__int32)INVALID_VALUE )
				{
					vdata->isMemArgument = true;
					vdata->homeMemoryOffset = a.stackOffset;
				}

				m_paArgumentVariables[ i ] = vdata;
			}
		}

		//------------------------------------------------------------------------------
		void CEFunction::_prepareVariables( CEmittable* first ) __QCMP_THROW
		{
			Cmp_unsigned__int32 i, count = m_FunctionPrototype.getArgumentsCount();
			if( count == 0 ) 
			{
				return;
			}

			for( i = 0; i < count; i++ )
			{
				VarData* vdata = m_paArgumentVariables[ i ];

				vdata->firstEmittable = first;		// This is where variable scope starts.
				vdata->lastEmittable = first;		// If this is not changed then it will be deallocated immediately.
			}
		}

		//------------------------------------------------------------------------------
		void CEFunction::_allocVariables( Cx86HLAContext& cc ) __QCMP_THROW
		{
			Cmp_unsigned__int32 i, count = m_FunctionPrototype.getArgumentsCount();
			if( count == 0 ) 
			{
				return;
			}

			for( i = 0; i < count; i++ )
			{
				VarData* vdata = m_paArgumentVariables[ i ];

				if( vdata->firstEmittable != 0 || vdata->isRegArgument || vdata->isMemArgument )
				{
					// Variable is used.
					if( vdata->registerIndex != INVALID_VALUE )
					{
						vdata->state = VARIABLE_STATE_REGISTER;
						// If variable is in register -> mark it as changed so it will not be lost by first spill.
						vdata->changed = true;
						cc._allocatedVariable( vdata );
					}
					else if( vdata->isMemArgument )
					{
						vdata->state = VARIABLE_STATE_MEMORY;
					}
				}
				else
				{
					vdata->registerIndex = static_cast< Cmp_unsigned__int32 >( INVALID_VALUE );		// Variable is not used.
				}
			}
		}

		//------------------------------------------------------------------------------
		void CEFunction::_preparePrologEpilog( Cx86HLAContext& cc) __QCMP_THROW
		{
			//const nsArch::nsx86::CpuInfo* cpuInfo = getCpuInfo();

			m_bPePushPop = true;
			m_bEmitEMMS = false;
			m_bEmitSFence = false;
			m_bEmitLFence = false;

			Cmp_unsigned__int32 accessibleMemoryBelowStack = 0;
			if( m_FunctionPrototype.getCallingConvention() == CALL_CONV_X64U ) 
			{
				accessibleMemoryBelowStack = 128;
			}

			if( m_bIsCaller && ( cc.getMemBytesTotal() > 0 || m_bIsStackAlignedByOsTo16Bytes ) )
			{
				m_bIsEspAdjusted = true;
			}

			if( cc.getMemBytesTotal() > accessibleMemoryBelowStack )
			{
				m_bIsEspAdjusted = true;
			}

			if( m_auiHints[ FUNCTION_HINT_NAKED ] != INVALID_VALUE )
			{
				m_bIsNaked = m_auiHints[ FUNCTION_HINT_NAKED ] ? true : false;
			}

			if( m_auiHints[ FUNCTION_HINT_PUSH_POP_SEQUENCE ] != INVALID_VALUE )
			{
				m_bPePushPop = m_auiHints[ FUNCTION_HINT_PUSH_POP_SEQUENCE ] ? true : false;
			}

			if( m_auiHints[ FUNCTION_HINT_EMMS ] != INVALID_VALUE )
			{
				m_bEmitEMMS = m_auiHints[ FUNCTION_HINT_EMMS ] ? true : false;
			}

			if( m_auiHints[ FUNCTION_HINT_SFENCE ] != INVALID_VALUE )
			{
				m_bEmitSFence = m_auiHints[ FUNCTION_HINT_SFENCE ] ? true : false;
			}

			if( m_auiHints[ FUNCTION_HINT_LFENCE ] != INVALID_VALUE )
			{
				m_bEmitLFence = m_auiHints[ FUNCTION_HINT_LFENCE ] ? true : false;
			}

			if( !m_bIsStackAlignedByOsTo16Bytes && !m_bIsNaked && ( cc.getMem16BlocksCount() + cc.getMem8BlocksCount() > 0 ) )
			{
				// Have to align stack to 16-bytes.
				m_bIsStackAlignedByFnTo16Bytes = true;
				m_bIsEspAdjusted = true;
			}

			m_uiModifiedAndPreservedGP  = cc.getModifiedGPRegisters() & m_FunctionPrototype.getPreservedGP() & ~nsCodeQOR::maskFromIndex( REG_INDEX_ESP );
			m_uiModifiedAndPreservedMM  = cc.getModifiedMMRegisters() & m_FunctionPrototype.getPreservedMM();
			m_uiModifiedAndPreservedXMM = cc.getModifiedXMMRegisters() & m_FunctionPrototype.getPreservedXMM();

			m_uiMovDqaInstruction = ( m_bIsStackAlignedByOsTo16Bytes || !m_bIsNaked ) ? INST_MOVDQA : INST_MOVDQU;

			// Prolog & Epilog stack size.
			{
				Cmp__int32 memGP = nsCodeQOR::bitCount( m_uiModifiedAndPreservedGP ) * sizeof(Cmp_int_ptr);
				Cmp__int32 memMM = nsCodeQOR::bitCount( m_uiModifiedAndPreservedMM ) * 8;
				Cmp__int32 memXMM = nsCodeQOR::bitCount( m_uiModifiedAndPreservedXMM ) * 16;

				if( m_bPePushPop )
				{
					m_iPePushPopStackSize = memGP;
					m_iPeMovStackSize = memXMM + nsCodeQOR::alignTo16( memMM );
				}
				else
				{
					m_iPePushPopStackSize = 0;
					m_iPeMovStackSize = memXMM + nsCodeQOR::alignTo16( memMM + memGP );
				}
			}

			if( m_bIsStackAlignedByFnTo16Bytes )
			{
				m_iPeAdjustStackSize += nsCodeQOR::deltaTo16( m_iPePushPopStackSize );
			}
			else
			{
				Cmp__int32 v = 16 - sizeof(Cmp_int_ptr);
				if( !m_bIsNaked ) 
				{
					v -= sizeof(Cmp_int_ptr);
				}

				v -= m_iPePushPopStackSize & 15;
				if( v < 0 )
				{
					v += 16;
				}
				m_iPeAdjustStackSize = v;

				//m_iPeAdjustStackSize += nsCodeQOR::deltaTo16( m_iPePushPopStackSize + v );
			}

			// Memory stack size.
			m_iMemStackSize = cc.getMemBytesTotal();
			m_iMemStackSize16 = nsCodeQOR::alignTo16( m_iMemStackSize );

			if( m_bIsNaked )
			{ 
				cc.setArgumentsBaseReg( REG_INDEX_ESP );
				cc.setArgumentsBaseOffset( m_bIsEspAdjusted ? ( m_iFunctionCallStackSize + m_iMemStackSize16 + m_iPeMovStackSize + m_iPePushPopStackSize + m_iPeAdjustStackSize ) : ( m_iPePushPopStackSize ) );
			}
			else
			{
				cc.setArgumentsBaseReg( REG_INDEX_EBP );
				cc.setArgumentsBaseOffset( sizeof(Cmp_int_ptr) );
			}

			cc.setVariablesBaseReg( REG_INDEX_ESP );
			cc.setVariablesBaseOffset( m_iFunctionCallStackSize );
			if( !m_bIsEspAdjusted )
			{
				cc.setVariablesBaseOffset( -m_iMemStackSize16 - m_iPeMovStackSize - m_iPeAdjustStackSize );
			}
		}

		//------------------------------------------------------------------------------
		void CEFunction::_dumpFunction( Cx86HLAContext& cc ) __QCMP_THROW
		{
			CLogger* logger = ( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->getLogger();
			assert( logger != 0 );

			Cmp_unsigned__int32 i;
			char _buf[ 1024 ];
			char* p;

			// Log function prototype.
			{
				Cmp_unsigned__int32 argumentsCount = m_FunctionPrototype.getArgumentsCount();
				bool first = true;

				logger->logString( "; Function Prototype:\n" );
				logger->logString( ";\n" );

				for( i = 0; i < argumentsCount; i++ )
				{
					const CFunctionPrototype::Argument& a = m_FunctionPrototype.getArguments()[ i ];
					VarData* vdata = m_paArgumentVariables[ i ];

					if( first )
					{
						logger->logString( "; IDX| Type     | Sz | Home           |\n" );
						logger->logString( "; ---+----------+----+----------------+\n" );
					}

					char* memHome = memHome = _buf;

					if( a.registerIndex != INVALID_VALUE )
					{
						CBaseReg regOp( a.registerIndex | REG_TYPE_GPN, 0 );
						//dumpOperand(memHome, &regOp, REG_TYPE_GPN )[0] = '\0';
					}
					else
					{
						CMem memOp;
						memOp.setBase( REG_INDEX_ESP );
						memOp.setDisplacement( a.stackOffset );
						//dumpOperand(memHome, &memOp, REG_TYPE_GPN )[0] = '\0';
					}

					logger->logFormat( "; %-3u| %-9s| %-3u| %-15s|\n",
						// Argument index.
						i,
						// Argument type.
						vdata->type < _VARIABLE_TYPE_COUNT ? variableInfo[ vdata->type ].name : "invalid",
						// Argument size.
						vdata->size,
						// Argument memory home.
						memHome
						);

					first = false;
				}
				logger->logString( ";\n" );
			}

			// Log variables.
			{
				Cmp_unsigned__int32 variablesCount = (Cmp_unsigned__int32)( ( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->getVarData().getLength() );
				bool first = true;

				logger->logString( "; Variables:\n" );
				logger->logString( ";\n" );

				for( i = 0; i < variablesCount; i++ )
				{
					VarData* vdata = ( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->getVarData()[ i ];

					// If this variable is not related to this function then skip it.
					if( vdata->scope != this )
					{
						continue;
					}

					// Get some information about variable type.
					const VariableInfo& vinfo = variableInfo[ vdata->type ];

					if( first )
					{
						logger->logString( "; ID | Type     | Sz | Home           | Register Access   | Memory Access     |\n" );
						logger->logString( "; ---+----------+----+----------------+-------------------+-------------------+\n" );
					}

					char* memHome = (char*)"[None]";
					if( vdata->homeMemoryData != 0 )
					{
						VarMemBlock* memBlock = reinterpret_cast< VarMemBlock* >( vdata->homeMemoryData );
						memHome = _buf;

						CMem memOp;
						if( vdata->isMemArgument )
						{
							const CFunctionPrototype::Argument& a = m_FunctionPrototype.getArguments()[ i ];

							memOp.setBase( cc.getArgumentsBaseReg() );
							memOp.setDisplacement( memOp.getDisplacement() + cc.getArgumentsBaseOffset() );
							memOp.setDisplacement( memOp.getDisplacement() + a.stackOffset );
						}
						else
						{
							memOp.setBase( cc.getVariablesBaseReg() );
							memOp.setDisplacement( memOp.getDisplacement() + cc.getVariablesBaseOffset() );
							memOp.setDisplacement( memOp.getDisplacement() + memBlock->offset );
						}
						//dumpOperand(memHome, &memOp, REG_TYPE_GPN )[0] = '\0';
					}

					logger->logFormat( "; %-3u| %-9s| %-3u| %-15s| r=%-4uw=%-4ux=%-4u| r=%-4uw=%-4ux=%-4u|\n",
						// Variable id.
						(Cmp_unsigned_int)( i & OPERAND_ID_VALUE_MASK ),
						// Variable type.
						vdata->type < _VARIABLE_TYPE_COUNT ? vinfo.name : "invalid",
						// Variable size.
						vdata->size,
						// Variable memory home.
						memHome,
						// Register access count.
						(unsigned int)vdata->registerReadCount,
						(unsigned int)vdata->registerWriteCount,
						(unsigned int)vdata->registerRWCount,
						// Memory access count.
						(unsigned int)vdata->memoryReadCount,
						(unsigned int)vdata->memoryWriteCount,
						(unsigned int)vdata->memoryRWCount
					);
					first = false;
				}
				logger->logString( ";\n" );
			}

			// Log modified registers.
			{
				p = _buf;

				Cmp_unsigned__int32 r;
				Cmp_unsigned__int32 modifiedRegisters = 0;

				for( r = 0; r < 3; r++ )
				{
					bool first = true;
					Cmp_unsigned__int32 regs;
					Cmp_unsigned__int32 type;

					switch( r )
					{
					case 0:
						regs = cc.getModifiedGPRegisters();
						type = REG_TYPE_GPN;
						p = nsCodeQOR::mycpy( p, "; GP : " );
						break;
					case 1:
						regs = cc.getModifiedMMRegisters();
						type = REG_TYPE_MM;
						p = nsCodeQOR::mycpy( p, "; MM : " );
						break;
					case 2:
						regs = cc.getModifiedXMMRegisters();
						type = REG_TYPE_XMM;
						p = nsCodeQOR::mycpy( p, "; XMM: " );
						break;
					default:
						assert( 0 );
					}

					for( i = 0; i < REG_NUM_BASE; i++ )
					{
						if( ( regs & nsCodeQOR::maskFromIndex( i ) ) != 0 )
						{
							if( !first ) 
							{ 
								*p++ = ','; 
								*p++ = ' '; 
							}
							p = nsArch::nsx86::dumpRegister( p, type, i );
							first = false;
							modifiedRegisters++;
						}
					}
					*p++ = '\n';
				}
				*p = '\0';

				logger->logFormat( "; Modified registers (%u):\n", (unsigned int)modifiedRegisters );
				logger->logString( _buf );
			}

			logger->logString( "\n" );
		}

		//------------------------------------------------------------------------------
		void CEFunction::_emitProlog( Cx86HLAContext& cc) __QCMP_THROW
		{
			Cmp_unsigned__int32 i, mask;
			Cmp_unsigned__int32 preservedGP  = m_uiModifiedAndPreservedGP;
			Cmp_unsigned__int32 preservedMM  = m_uiModifiedAndPreservedMM;
			Cmp_unsigned__int32 preservedXMM = m_uiModifiedAndPreservedXMM;

			Cmp__int32 stackSubtract = m_iFunctionCallStackSize + m_iMemStackSize16 + m_iPeMovStackSize + m_iPeAdjustStackSize;
			Cmp__int32 nspPos;

			if( ( dynamic_cast< CHighLevelAssemblerBase* >( m_pHLAssembler ) )->getLogger() )
			{
				// Here function prolog starts.
				( dynamic_cast< Cx86HLAssembler* >( m_pHLAssembler ) )->comment( "Prolog" );
			}

			// Emit standard prolog entry code (but don't do it if function is set to be
			// naked).
			//
			// Also see the _prologEpilogStackAdjust variable. If function is naked (so
			// prolog and epilog will not contain "push ebp" and "mov ebp, esp", we need
			// to adjust stack by 8 bytes in 64-bit mode (this will give us that stack
			// will remain aligned to 16 bytes).
			if( !m_bIsNaked )
			{
				( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_PUSH, &Cx86CPUCore::nbp );
				( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_MOV, &Cx86CPUCore::nbp, &Cx86CPUCore::nsp );
			}

			// Align manually stack-pointer to 16-bytes.
			if( m_bIsStackAlignedByFnTo16Bytes )
			{
				assert( !m_bIsNaked );
				CImm Imm( imm( -16 ) );
				( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_AND, &Cx86CPUCore::nsp, &Imm );
			}

			// Save GP registers using PUSH/POP.
			if( preservedGP && m_bPePushPop )
			{
				for( i = 0, mask = 1; i < REG_NUM_GP; i++, mask <<= 1 )
 				{
					if( preservedGP & mask )
					{
						CGPReg Reg( gpn( i ) );
						( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_PUSH, &Reg );
					}
				}
			}

			if( m_bIsEspAdjusted )
			{
				nspPos = m_iMemStackSize16;
				if( stackSubtract )
				{
					CImm Imm( imm( stackSubtract ) );
					( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_SUB, &Cx86CPUCore::nsp, &Imm );
				}
			}
			else
			{
				nspPos = -( m_iPeMovStackSize + m_iPeAdjustStackSize );
				//if (m_bPePushPop) nspPos += nsCodeQOR::bitCount(preservedGP) * sizeof(Cmp_int_ptr);
			}

			// Save XMM registers using MOVDQA/MOVDQU.
			if( preservedXMM )
			{
				for( i = 0, mask = 1; i < REG_NUM_XMM; i++, mask <<= 1 )
				{
					if( preservedXMM & mask )
					{
						CMem Mem( dqword_ptr( Cx86CPUCore::nsp, nspPos ) );
						CXMMReg XMMReg( xmm( i ) );
						( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( m_uiMovDqaInstruction, &Mem, &XMMReg );
						nspPos += 16;
					}
				}
			}

			// Save MM registers using MOVQ.
			if( preservedMM )
			{
				for( i = 0, mask = 1; i < 8; i++, mask <<= 1 )
				{
					if( preservedMM & mask )
					{
						CMem Mem( qword_ptr( Cx86CPUCore::nsp, nspPos ) );
						CMMReg MMReg( mm( i ) );
						( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_MOVQ, &Mem, &MMReg );
						nspPos += 8;
					}
				}
			}

			// Save GP registers using MOV.
			if( preservedGP && !m_bPePushPop )
			{
				for( i = 0, mask = 1; i < REG_NUM_GP; i++, mask <<= 1 )
				{
					if( preservedGP & mask )
					{ 
						CMem Mem( sysint_ptr( Cx86CPUCore::nsp, nspPos ) );
						CGPReg Reg( gpn( i ) );
						( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_MOV, &Mem, &Reg );
						nspPos += sizeof( Cmp_int_ptr );
					}
				}
			}

			if( ( dynamic_cast< Cx86HLAssembler* >( m_pHLAssembler ) )->getLogger() )
			{
				( dynamic_cast< Cx86HLAssembler* >( m_pHLAssembler ) )->comment( "Body" );
			}
		}

		//------------------------------------------------------------------------------
		void CEFunction::_emitEpilog( Cx86HLAContext& cc) __QCMP_THROW
		{
			//TODO: const nsArch::nsx86::CpuInfo* cpuInfo = getCpuInfo();

			Cmp_unsigned__int32 i, mask;
			Cmp_unsigned__int32 preservedGP  = m_uiModifiedAndPreservedGP;
			Cmp_unsigned__int32 preservedMM  = m_uiModifiedAndPreservedMM;
			Cmp_unsigned__int32 preservedXMM = m_uiModifiedAndPreservedXMM;

			Cmp__int32 stackAdd = m_iFunctionCallStackSize + m_iMemStackSize16 + m_iPeMovStackSize + m_iPeAdjustStackSize;
			Cmp__int32 nspPos;

			nspPos = (m_bIsEspAdjusted) ? (m_iMemStackSize16) : -(m_iPeMovStackSize + m_iPeAdjustStackSize);

			if( ( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->getLogger() )
			{
				( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->comment( "Epilog" );
			}

			// Restore XMM registers using MOVDQA/MOVDQU.
			if( preservedXMM )
			{
				for( i = 0, mask = 1; i < REG_NUM_XMM; i++, mask <<= 1 )
				{
					if( preservedXMM & mask )
					{
						CXMMReg XMMReg( xmm( i ) );
						CMem Mem( dqword_ptr( Cx86CPUCore::nsp, nspPos ) );
						( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( m_uiMovDqaInstruction, &XMMReg, &Mem );
						nspPos += 16;
					}
				}
			}

			// Restore MM registers using MOVQ.
			if( preservedMM )
			{
				for( i = 0, mask = 1; i < 8; i++, mask <<= 1 )
				{
					if( preservedMM & mask )
					{
						CMMReg MMReg( mm( i ) );
						CMem Mem( qword_ptr( Cx86CPUCore::nsp, nspPos ) );
						( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_MOVQ, &MMReg, &Mem );
						nspPos += 8;
					}
				}
			}

			// Restore GP registers using MOV.
			if( preservedGP && !m_bPePushPop )
			{
				for( i = 0, mask = 1; i < REG_NUM_GP; i++, mask <<= 1 )
				{
					if( preservedGP & mask )
					{
						CGPReg Reg( gpn( i ) );
						CMem Mem( sysint_ptr( Cx86CPUCore::nsp, nspPos ) );
						( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_MOV, &Reg, &Mem );
						nspPos += sizeof( Cmp_int_ptr );
					}
				}
			}

			if( m_bIsEspAdjusted && stackAdd != 0 )
			{
				CImm Imm( imm( stackAdd ) );
				( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_ADD, &Cx86CPUCore::nsp, &Imm );
			}

			// Restore GP registers using POP.
			if( preservedGP && m_bPePushPop )
			{
				for( i = REG_NUM_GP - 1, mask = 1 << i; (Cmp__int32)i >= 0; i--, mask >>= 1 )
				{
					if( preservedGP & mask )
					{
						CGPReg Reg( gpn( i ) );
						( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_POP, &Reg );
					}
				}
			}

			// Emit Emms.
			if( m_bEmitEMMS )
			{
				( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_EMMS );
			}

			// Emit SFence / LFence / MFence.
			if( m_bEmitSFence &&  m_bEmitLFence )
			{
				( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_MFENCE ); // MFence == SFence & LFence.
			}

			if( m_bEmitSFence && !m_bEmitLFence ) 
			{
				( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_SFENCE ); // Only SFence.
			}

			if( !m_bEmitSFence &&  m_bEmitLFence ) 
			{
				( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_LFENCE ); // Only LFence.
			}

			// Emit standard epilog leave code (if needed).
			if( !m_bIsNaked )
			{
				CpuInfo cpuinfo;
				CpuInfo* ci = &cpuinfo;
				CpuInfoStatic info;
				info.detectCpuInfo( ci );

				if( ci->vendorId == QOR_ARCH_X86_VENDOR_AMD )
				{
					// AMD seems to prefer LEAVE instead of MOV/POP sequence.
					( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_LEAVE );
				}
				else
				{
					( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_MOV, &Cx86CPUCore::nsp, &Cx86CPUCore::nbp );
					( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_POP, &Cx86CPUCore::nbp );
				}
			}

			// Emit return using correct instruction.
			if( m_FunctionPrototype.getCalleePopsStack() )
			{
				CImm Imm( imm( (Cmp__int16)m_FunctionPrototype.getArgumentsStackSize() ) );
				( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_RET, &Imm );
			}
			else
			{
				( dynamic_cast< Cx86HLAIntrinsics* >( m_pHLAssembler ) )->emit( INST_RET );
			}
		}

		//------------------------------------------------------------------------------
		void CEFunction::reserveStackForFunctionCall( Cmp__int32 size )
		{
			size = nsCodeQOR::alignTo16( size );

			if( size > m_iFunctionCallStackSize )
			{
				m_iFunctionCallStackSize = size;
			}
			m_bIsCaller = true;
		}

	}//nsx86
}//nsArch

#endif//( QOR_ARCH == QOR_ARCH_X86_32 || QOR_ARCH == QOR_ARCH_X86_64 )
