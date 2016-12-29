//main.cpp

// Copyright Querysoft Limited 2013
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

//primary implementation file for BlanketQOR, the QOR code coverage and analysis tool

#include "AppocritaQOR/Applications/TerminalApp.h"

#define PDC_DLL_BUILD
#include "Qurses/curses.h"
#include <stdlib.h>
#include <time.h>

//------------------------------------------------------------------------------
static int next_j( int j )
{
    if( j == 0 )
	{
        j = 4;
	}
    else
	{
        --j;
	}

    if( has_colors() )
    {
        int z = rand() % 3;
        chtype color = COLOR_PAIR( z );

        if( z )
		{
            color |= A_BOLD;
		}

        attrset( color );
    }

    return j;
}

//------------------------------------------------------------------------------
class CBlanketQORApplication : public nsAppocrita::CTerminalApp
{
public:

	//------------------------------------------------------------------------------
	CBlanketQORApplication()
	{
		//Setup application
	}

	//------------------------------------------------------------------------------
	virtual ~CBlanketQORApplication()
	{
		//Teardown application
	}

	//------------------------------------------------------------------------------
	virtual int Run( void )
	{
		//execute application - will eventually be standardised into one or more base classes
		m_GUIRef = m_TerminalGUI().Session();

		int x, y, j, r, c, seed;
		static int xpos[5], ypos[5];

	#ifdef XCURSES
		Xinitscr(argc, argv);
	#else
		initscr();
	#endif

		border( 46, 47, 48, 49, 50, 51, 52, 53 );

		seed = time((time_t *)0);
		srand(seed);

		if( has_colors() )
		{
			int bg = COLOR_BLACK;

			start_color();

#if defined( NCURSES_VERSION ) || ( defined( PDC_BUILD ) && PDC_BUILD > 3000 )
			if( use_default_colors() == 0 )
			{
				bg = -1;
			}
#endif
			init_pair( 1, COLOR_BLUE, bg );
			init_pair( 2, COLOR_CYAN, bg );
		}

		nl();
		noecho();
		curs_set(0);
		timeout(0);
		keypad(stdscr, TRUE);

		r = LINES - 4;
		c = COLS - 4;

		for (j = 5; --j >= 0;)
		{
			xpos[j] = rand() % c + 2;
			ypos[j] = rand() % r + 2;
		}

		for (j = 0;;)
		{
			x = rand() % c + 2;
			y = rand() % r + 2;

			mvaddch(y, x, '.');

			mvaddch(ypos[j], xpos[j], 'o');

			j = next_j(j);
			mvaddch(ypos[j], xpos[j], 'O');

			j = next_j(j);
			mvaddch(ypos[j] - 1, xpos[j], '-');
			mvaddstr(ypos[j], xpos[j] - 1, "|.|");
			mvaddch(ypos[j] + 1, xpos[j], '-');

			j = next_j(j);
			mvaddch(ypos[j] - 2, xpos[j], '-');
			mvaddstr(ypos[j] - 1, xpos[j] - 1, "/ \\");
			mvaddstr(ypos[j], xpos[j] - 2, "| O |");
			mvaddstr(ypos[j] + 1, xpos[j] - 1, "\\ /");
			mvaddch(ypos[j] + 2, xpos[j], '-');

			j = next_j(j);
			mvaddch(ypos[j] - 2, xpos[j], ' ');
			mvaddstr(ypos[j] - 1, xpos[j] - 1, "   ");
			mvaddstr(ypos[j], xpos[j] - 2, "     ");
			mvaddstr(ypos[j] + 1, xpos[j] - 1, "   ");
			mvaddch(ypos[j] + 2, xpos[j], ' ');

			xpos[j] = x;
			ypos[j] = y;

			switch (getch())
			{
			case 'q':
			case 'Q':
				curs_set(1);
				endwin();
				return EXIT_SUCCESS;
			case 's':
				nodelay(stdscr, FALSE);
				break;
			case ' ':
				nodelay(stdscr, TRUE);
	#ifdef KEY_RESIZE
				break;
			case KEY_RESIZE:
	# ifdef PDCURSES
				resize_term(0, 0);
				erase();
	# endif
				r = LINES - 4;
				c = COLS - 4;
	#endif
			}
			napms(50);
		}
		return 0;
	}
};

//------------------------------------------------------------------------------
int main( int argc, char* argv, char** env )
{
	CBlanketQORApplication BlanketQORApplication;

	return BlanketQORApplication.Run();
}