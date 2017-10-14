//WinQLFileSystem.cpp

// Copyright Querysoft Limited 2013, 2015
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

#include "WinQL/System/FileSystem/WinQLFileSystem.h"
#include "WinQL/System/FileSystem/WinQLVolumeManagement.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	
	//--------------------------------------------------------------------------------
	CFileSystem::CFileSystem()
	{
		Volumes.Attach(this, &CFileSystem::GetVolumes, nullptr);
	}

	//--------------------------------------------------------------------------------
	CFileSystem::CFileSystem( const CFileSystem& src )
	{
		*this = src;
	}

	//--------------------------------------------------------------------------------
	CFileSystem& CFileSystem::operator = ( const CFileSystem& src )
	{
		if( &src != this )
		{
			m_Volumes = src.m_Volumes;
		}

		return *this;
	}

	//--------------------------------------------------------------------------------
	CFileSystem::~CFileSystem()
	{
		//m_Volumes.erase(m_Volumes.begin(), m_Volumes.end());
	}

	//--------------------------------------------------------------------------------
	std::vector< CVolume::ref_type > CFileSystem::GetVolumes()
	{
		if (m_Volumes.size() == 0)
		{
			CFindVolume FindVolume;
			do
			{
				m_Volumes.push_back(FindVolume.Volume());
			} while (FindVolume.Next());

		}
		return m_Volumes;
	}

}//nsWin32


