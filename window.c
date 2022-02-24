/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:34:41 by conguyen          #+#    #+#             */
/*   Updated: 2022/02/24 14:47:52 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

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
	win->win_err = newwin(3, 56, 23, 0); /* Error window */
	win->win_help = newwin(13, 56, 27, 0); /* Error window */
	win->win_main = newwin(20, 27, 0, 0); /* Main window */
	win->win_info = newwin(20, 28, 0, 28); /* Main window */
	box(win->win_main, 0, 0);
	box(win->win_info, 0, 0);
	box(win->win_input, 0, 0);
}

void	refresh_window(t_win win)
{

	wrefresh(win.win_input);
	wrefresh(win.win_main);
	wrefresh(win.win_info);
	wrefresh(win.win_help);
	wrefresh(win.win_err);
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
	wclear(win.win_help);
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

void	add_color(int c, t_win win, char *color, char *str)
{
	int	z = 0;
	int	start;
	int	end;

	end = 5 * c;
	start = end - 5;
	for (start; start < end; start++)
	{
		if (color[z] == 103)
		{
			wattron(win.win[start], COLOR_PAIR(GREEN));
			mvwaddch(win.win[start], 1, 1, ' ');
			wborder(win.win[start], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			mvwaddch(win.win[start], 1, 2, str[z]);
			mvwaddch(win.win[start], 1, 3, ' ');
			wattroff(win.win[start], COLOR_PAIR(GREEN));
		}
		else if (color[z] == 121)
		{
			wattron(win.win[start], COLOR_PAIR(YELLOW));
			mvwaddch(win.win[start], 1, 1, ' ');
			wborder(win.win[start], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			mvwaddch(win.win[start], 1, 2, str[z]);
			mvwaddch(win.win[start], 1, 3, ' ');
			wattroff(win.win[start], COLOR_PAIR(YELLOW));
		}
		else
		{
			wattron(win.win[start], COLOR_PAIR(WHITE));
			mvwaddch(win.win[start], 1, 1, ' ');
			wborder(win.win[start], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			mvwaddch(win.win[start], 1, 2, str[z]);
			mvwaddch(win.win[start], 1, 3, ' ');
			wattroff(win.win[start], COLOR_PAIR(WHITE));
		}
		z++;
	}
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

void	initiate_colors()
{
	init_pair(GREEN, COLOR_BLACK, COLOR_GREEN);
	init_pair(YELLOW, COLOR_BLACK, COLOR_YELLOW);
	init_pair(WHITE, COLOR_BLACK, COLOR_WHITE);
}

void	initialize_help_box(t_win win)
{
	box(win.win_help, ' ', ' ');
	mvwaddstr(win.win_help, 0, 25, "Usage");
	mvwaddstr(win.win_help, 2, 2, "1: Type word in the input field.");
	mvwaddstr(win.win_help, 4, 2, "2: Type color combination using:");
	mvwaddstr(win.win_help, 5, 5, "'g' for correct char and position.");
	mvwaddstr(win.win_help, 6, 5, "'y' for correct char, wrong postion.");
	mvwaddstr(win.win_help, 7, 5, "'s' for char doesn't exist.");
	mvwaddstr(win.win_help, 9, 2, "3: Type '!r' in the input field to restart");
	mvwaddstr(win.win_help, 11, 2, "4: Type '!q' in the input field to quit");
}
