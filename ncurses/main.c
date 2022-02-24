/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:11:36 by conguyen          #+#    #+#             */
/*   Updated: 2022/02/24 11:57:42 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <string.h> 
#include <stdlib.h>

#define GREEN	1
#define YELLOW	2
#define WHITE	3

typedef struct s_win
{
	WINDOW *win[30];
	WINDOW *win_input;
	WINDOW *win_err;
	WINDOW *win_main;
	WINDOW *win_info;
}	t_win;

void	initialize_window(t_win *win)
{
	int	row_add;
	int	col_add;

	row_add = 1;
	col_add = 1;
	for (int x = 0; x < 30; x++)/* Window blocks inside main window*/
	{
		win->win[x] = newwin(3, 5, row_add, col_add);
		col_add = col_add + 5;
		if (x == 4 || x == 9 || x == 14 || x == 19 || x == 24)
		{
			row_add = row_add + 3;
			col_add = 1;
		}
		box(win->win[x], 0, 0);
	}
	win->win_input = newwin(3, 27, 20, 0); /* Input window */
	win->win_err = newwin(30, 50, 23, 0); /* Error window */
	win->win_main = newwin(20, 27, 0, 0); /* Main window */
	win->win_info = newwin(20, 27, 0, 28); /* Main window */
	box(win->win_main, 0, 0);
	box(win->win_info, 0, 0);
}

void	refresh_window(t_win win)
{
	for (int x = 0; x < 30; x++)
		wrefresh(win.win[x]);
}

void	clear_window(t_win win)
{
	for (int x = 0; x < 30; x++)
		wclear(win.win[x]);
	wclear(win.win_input);
	wclear(win.win_main);
	wclear(win.win_err);
	wclear(win.win_info);
}

void	add_word(int c, t_win win, char *str)
{
	if (c == 1)
	{
		mvwaddch(win.win[0], 1, 2, str[0]);
		mvwaddch(win.win[1], 1, 2, str[1]);
		mvwaddch(win.win[2], 1, 2, str[2]);
		mvwaddch(win.win[3], 1, 2, str[3]);
		mvwaddch(win.win[4], 1, 2, str[4]);
	}
	else if (c == 2)
	{
		mvwaddch(win.win[5], 1, 2, str[0]);
		mvwaddch(win.win[6], 1, 2, str[1]);
		mvwaddch(win.win[7], 1, 2, str[2]);
		mvwaddch(win.win[8], 1, 2, str[3]);
		mvwaddch(win.win[9], 1, 2, str[4]);
	}
	else if (c == 3)
	{
		mvwaddch(win.win[10], 1, 2, str[0]);
		mvwaddch(win.win[11], 1, 2, str[1]);
		mvwaddch(win.win[12], 1, 2, str[2]);
		mvwaddch(win.win[13], 1, 2, str[3]);
		mvwaddch(win.win[14], 1, 2, str[4]);
	}
	else if (c == 4)
	{
		mvwaddch(win.win[15], 1, 2, str[0]);
		mvwaddch(win.win[16], 1, 2, str[1]);
		mvwaddch(win.win[17], 1, 2, str[2]);
		mvwaddch(win.win[18], 1, 2, str[3]);
		mvwaddch(win.win[19], 1, 2, str[4]);
	}
	else if (c == 5)
	{
		mvwaddch(win.win[20], 1, 2, str[0]);
		mvwaddch(win.win[21], 1, 2, str[1]);
		mvwaddch(win.win[22], 1, 2, str[2]);
		mvwaddch(win.win[23], 1, 2, str[3]);
		mvwaddch(win.win[24], 1, 2, str[4]);
	}
	else if (c == 6)
	{
		mvwaddch(win.win[25], 1, 2, str[0]);
		mvwaddch(win.win[26], 1, 2, str[1]);
		mvwaddch(win.win[27], 1, 2, str[2]);
		mvwaddch(win.win[28], 1, 2, str[3]);
		mvwaddch(win.win[29], 1, 2, str[4]);
	}
}

int	add_color(int c, t_win win, char *color, char *str)
{
	int	z = 0;
	int	correct = 0;

	if (c == 1)
	{
		for (int x = 0; x < 5; x++)
		{
			if (color[x] == 103)
			{
				wattron(win.win[x], COLOR_PAIR(GREEN));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[x]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(GREEN));
				correct++;
			}
			else if (color[x] == 121)
			{
				wattron(win.win[x], COLOR_PAIR(YELLOW));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[x]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(YELLOW));
			}
			else
			{
				wattron(win.win[x], COLOR_PAIR(WHITE));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[x]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(WHITE));
			}
		}
	}
	else if (c == 2)
	{
		z = 0;
		for (int x = 5; x < 10; x++)
		{
			if (color[z] == 103)
			{
				wattron(win.win[x], COLOR_PAIR(GREEN));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[z]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(GREEN));
				correct++;
			}
			else if (color[z] == 121)
			{
				wattron(win.win[x], COLOR_PAIR(YELLOW));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[z]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(YELLOW));
			}
			else
			{
				wattron(win.win[x], COLOR_PAIR(WHITE));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[z]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(WHITE));
			}
			z++;
		}
	}
	else if (c == 3)
	{
		z = 0;
		for (int x = 10; x < 15; x++)
		{
			if (color[z] == 103)
			{
				wattron(win.win[x], COLOR_PAIR(GREEN));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[z]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(GREEN));
				correct++;
			}
			else if (color[z] == 121)
			{
				wattron(win.win[x], COLOR_PAIR(YELLOW));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[z]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(YELLOW));
			}
			else
			{
				wattron(win.win[x], COLOR_PAIR(WHITE));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[z]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(WHITE));
				correct++;
			}
			z++;
		}
	}
	else if (c == 4)
	{
		z = 0;
		for (int x = 15; x < 20; x++)
		{
			if (color[z] == 103)
			{
				wattron(win.win[x], COLOR_PAIR(GREEN));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[z]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(GREEN));
				correct++;
			}
			else if (color[z] == 121)
			{
				wattron(win.win[x], COLOR_PAIR(YELLOW));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[z]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(YELLOW));
			}
			else
			{
				wattron(win.win[x], COLOR_PAIR(WHITE));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[z]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(WHITE));
			}
			z++;
		}
	}
	else if (c == 5)
	{
		z = 0;
		for (int x = 20; x < 25; x++)
		{
			if (color[z] == 103)
			{
				wattron(win.win[x], COLOR_PAIR(GREEN));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[z]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(GREEN));
				correct++;
			}
			else if (color[z] == 121)
			{
				wattron(win.win[x], COLOR_PAIR(YELLOW));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[z]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(YELLOW));
			}
			else
			{
				wattron(win.win[x], COLOR_PAIR(WHITE));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[z]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(WHITE));
			}
			z++;
		}
	}
	else if (c == 6)
	{
		z = 0;
		for (int x = 25; x < 30; x++)
		{
			if (color[z] == 103)
			{
				wattron(win.win[x], COLOR_PAIR(GREEN));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[z]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(GREEN));
				correct++;
			}
			else if (color[z] == 121)
			{
				wattron(win.win[x], COLOR_PAIR(YELLOW));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[z]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(YELLOW));
			}
			else
			{
				wattron(win.win[x], COLOR_PAIR(WHITE));
				mvwaddch(win.win[x], 1, 1, ' ');
				wborder(win.win[x], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
				mvwaddch(win.win[x], 1, 2, str[z]);
				mvwaddch(win.win[x], 1, 3, ' ');
				wattroff(win.win[x], COLOR_PAIR(WHITE));
			}
			z++;
		}
	}
	return (correct);
}

int	check_color_input(char* color)
{
	for (int x = 0; x < 5; x++)
	{
		if (color[x] != 'g' && color[x] != 's' && color[x] != 'y')
			return (0);
	}
	return (1);
}

int main()
{
	char	str[20];
	char	color[20];
	t_win	win;
	int		c;
	int		word;
	int		correct;
	int		color_check;

	initscr(); /* initiate ncurses window*/
	start_color();
	init_pair(GREEN, COLOR_BLACK, COLOR_GREEN);
	init_pair(YELLOW, COLOR_BLACK, COLOR_YELLOW);
	init_pair(WHITE, COLOR_BLACK, COLOR_WHITE);
	initialize_window(&win);
	wrefresh(win.win_input);
	wrefresh(win.win_main);
	wrefresh(win.win_info);
	refresh_window(win);
	cbreak();

	box(win.win_input, 0, 0);
	word = 1;
	correct = 0;
	while (1)
	{
		mvwprintw(win.win_input, 1, 1, "Enter word: ");
		wrefresh(win.win_input);
		mvwgetstr(win.win_input, 1, 13, str);
		wclear(win.win_input);
		box(win.win_input, 0, 0);
		if (str[0] == 33 && str[1] == 113)
		{
			break ;
		}
		else if (strlen(str) != 5)
		{
			mvwprintw(win.win_err, 0, 1,"Word needs to be 5 characters long!");
			wrefresh(win.win_err);
		}
		else
		{
			add_word(word, win, str);
			refresh_window(win);
			color_check = 0;
			while (1)
			{
				mvwprintw(win.win_input, 1, 1, "Enter color: ");
				wrefresh(win.win_input);
				mvwgetstr(win.win_input, 1, 14, color);
				wclear(win.win_input);
				box(win.win_input, 0, 0);
				color_check = check_color_input(color);
				if (strlen(color) != 5)
				{
					mvwprintw(win.win_err, 0, 1,"Color needs to be 5 characters long!");
					wrefresh(win.win_err);
				}
				else if(color_check == 0)
				{
					mvwprintw(win.win_err, 0, 1,"Incorrect input! accepted char: 'g', 'y' and 's'");
					wrefresh(win.win_err);
				}
				else
				{
					wclear(win.win_err);
					wrefresh(win.win_err);
					break ;
				}
			}
			correct = add_color(word, win, color, str);
			refresh_window(win);
			wclear(win.win_input);
			box(win.win_input, 0, 0);
			word++;
		}
		if (correct == 5)
		{
			mvwprintw(win.win_info, 1, 1, "Correct word: %s!", str);
			wrefresh(win.win_info);
		}
		else
			correct = 0;
	}
	clear_window(win);
	endwin();
	return (0);
}