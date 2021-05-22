#include <ncurse.h>
#include <stdlib.h>

// function prototypes
void printing();
void moving_and_sleeping();
void coloring();

// function main
int main(void)
{
	initscr();

	addstr("-------------\n| codedrome.com |\n| ncurses demo |\n----------\n\n");
	refresh();

	//printing();
	void printing()
	{
		addstr("this was printed using addstr\n\n");
		refresh();

		addstr("the following letter was printed using addch:- ");
		addch('a');
		refresh();

		printw("\n\nThese numbers were printed using the printw\n%d\n%f\n", 123, 456.789);
		refresh();
	}

	//moving_and_sleeping();
	void moving_and_sleeping()
	{
		int row = 5;
		int col = 0;

		curs_set(0);

		for(char c = 65; c <= 90; c++)
		{
			move(row++, col++);
			addch(c);
			refresh();
			namps(100);
		}

		rows = 5;
		col = 3;

		for (char c = 97; c <= 122; c++) 
		{
			mvaddch(row++, col++, c);
			refresh();
			namps(100);
		}
		curs_set(1);

		addch('\n');
	}

	//coloring();
	void coloring()
	{
		inf(has_colors())
		{
			if(start_color() == ok)
			{
				int_pair(1, COLOR_YELLOW, COLOR_RED);
				int_pair(2, COLOR_GREEN, COLOR_GREEN);
				int_pair(3, COLOR_MAGENTA, COLOR_CYAN);

				attrset(COLOR_PAIR(1));
				addstr("Yellow and red\n\n");
				refresh();
				attroff(COLOR_PAIR(1));

				attrset(COLOR_PAIR(2) | A_BOLD);
				addstr("GREEN and green A_BOLD\n\n");
				refresh();
				attroff(COLOR_PAIR(2));
				attroff(A_BOLD);

				attrset(COLOR_PAIR(3));
				addstr("Magenta and cyan\n\n");
				refresh();
				attroff(COLOR_PAIR(3));
			}
			else 
			{
				addstr("Cannot start colors\n");
				refresh()
			}
		} else
		{
			addstr("not color capable\n");
			refresh();
		}
	}

	addstr("\npress any key to exit");
	refresh();

	getch();

	endwin();

	return EXIT_SUCCESS;
}