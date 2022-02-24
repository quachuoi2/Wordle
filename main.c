/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:07:55 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/24 14:49:19 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

void	store_words(char (*w_list)[TOTAL_WORDS + 1][6])
{
	int		fd;
	int		i;
	char	*s;

	fd = open("list_of_all", O_RDONLY);
	i = 0;
	while (get_next_line(fd, &s))
	{
		ft_strcpy((*w_list)[i], s);
		free(s);
		i++;
	}
	close(fd);
}

int	main(void)
{
	char	w_list[TOTAL_WORDS + 1][6];
	char	after_list[TOTAL_WORDS + 1][6];
	char	*word;
	char	*color;
	int		i;
	int		guess;
	int		color_check;
	t_win	win;
	int		count;
	int		column;
	int		row;
	int		restart_check;

	initscr(); /*initiate ncurses window*/
	start_color(); /*start ncurses colors*/
	initiate_colors();
	initialize_window(&win);
	initialize_help_box(win);
	refresh_window(win);
	cbreak();

	store_words(&w_list);
	w_list[TOTAL_WORDS][0] = '\0';
	word = NULL;
	color = NULL;
	guess = 1;
	count = 18;
	if (!initializer(&word, &color))
		return (0);
	while (1)
	{
		mvwprintw(win.win_input, 1, 1, "Enter word: ");
		wrefresh(win.win_input);
		mvwgetstr(win.win_input, 1, 13, word);
		wclear(win.win_input);
		box(win.win_input, 0, 0);
		if (word[0] == 33 && word[1] == 113) /*type !q to quit*/
			break ;
		else if (word[0] == 33 && word[1] == 114) /*type !r to restart*/
		{
			clear_window(win);
			initialize_window(&win);
			initialize_help_box(win);
			refresh_window(win);
			guess = 1;
			count = 18;
			store_words(&w_list);
			w_list[TOTAL_WORDS][0] = '\0';
		}
		else if (strlen(word) != 5) /*Check that word is 5 char long*/
		{
			mvwprintw(win.win_err, 0, 1,"Word needs to be 5 characters long!");
			wrefresh(win.win_err);
		}
		else
		{
			add_word(guess, win, word);
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
				if (color[0] == 33 && color[1] == 113) /*type !q to quit*/
				{
					clear_window(win);
					endwin();
					exit(0);
				}
				if (color[0] == 33 && color[1] == 114) /*type !r to restart*/
				{
					restart_check = 1;
					break ;
				}
				else if (strlen(color) != 5) /*Check that color is 5 char long*/
				{
					mvwprintw(win.win_err, 0, 1,"Color needs to be 5 characters long!");
					wrefresh(win.win_err);
				}
				else if(color_check == 0) /*Check that color only has 'g', 'y' or 's' chars*/
				{
					mvwprintw(win.win_err, 0, 1,"Incorrect input! accepted char: 'g', 'y' and 's'");
					wrefresh(win.win_err);
				}
				else
				{
					wclear(win.win_info);
					box(win.win_info, 0, 0);
					check_word(&w_list, &after_list, word, color);
					i = 0;
					column = 1;
					row = 1;
					while (after_list[i][0] != '\0') /*Print suggested words to info window*/
					{
						ft_strcpy(w_list[i], after_list[i]);
						mvwprintw(win.win_info, column++, row, "%s", after_list[i]);
						if (i == 70)
						{
							mvwprintw(win.win_info, column++, row, ".....");
							break ;
						}
						if (i == count - 1)
						{
							column = 1;
							row = row + 7;
							count = count + 18;
						}
						i++;
					}
					w_list[i][0] = '\0';
					wrefresh(win.win_info);
					wclear(win.win_err);
					wrefresh(win.win_err);
					break ;
				}
			}
			if (restart_check == 1) /*restart, if !r was typed in color input*/
			{
				restart_check = 0;
				clear_window(win);
				initialize_window(&win);
				initialize_help_box(win);
				refresh_window(win);
				guess = 1;
				count = 18;
				store_words(&w_list);
				w_list[TOTAL_WORDS][0] = '\0';
			}
			else
			{
				add_color(guess, win, color, word);
				refresh_window(win);
				wclear(win.win_input);
				box(win.win_input, 0, 0);
				guess++;
			}
		}
	}
	clear_window(win);
	endwin();
	freer(&word, &color);
	return (0);
}
