/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:07:55 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/24 17:12:18 by qnguyen          ###   ########.fr       */
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

void	restart_prog(t_win *win)
{
	clear_window(*win);
	initialize_window(&(*win));
	initialize_help_box(*win);
	refresh_window(*win);
}

int	check_color(t_win *win, char *word, char *color, char w_list[12973][6], char after_list[12973][6])
{
	int	color_check;
	int	i;
	int	column;
	int	row;
	int	count;

	count = 18;
	while (1)
	{
		mvwprintw((*win).win_input, 1, 1, "Enter color: ");
		box((*win).win_input, 0, 0);
		wrefresh((*win).win_input);
		mvwgetstr((*win).win_input, 1, 14, color);
		wclear((*win).win_input);
		color_check = check_color_input(color);
		if (color[0] == '!' && color[1] == 'q') /*type !q to quit*/
			exit_bundle(win, word, color);
		else if (color[0] == '!' && color[1] == 'r') /*type !r to restart*/
			return (1);
		else if (strlen(color) != 5) /*Check that color is 5 char long*/
			print_ui(win, "Color needs to be 5 characters long!");
		else if(color_check == 0) /*Check that color only has 'g', 'y' or 's' chars*/
			print_ui(win, "Incorrect input! Accepted char: 'g', 'y' and 's'");
		else
		{
			wclear((*win).win_info);
			box((*win).win_info, 0, 0);
			check_word(w_list, after_list, word, color);
			i = 0;
			column = 1;
			row = 1;
			while (after_list[i][0] != '\0') /*Print suggested words to info window*/
			{
				ft_strcpy(w_list[i], after_list[i]);
				if (i < 71)
					mvwprintw((*win).win_info, column++, row, "%s", after_list[i]);
				else if (i > 70)
					mvwprintw((*win).win_info, column++, row, ".....");
				if (i == count - 1)
				{
					column = 1;
					row = row + 7;
					count = count + 18;
				}
				i++;
			}
			w_list[i][0] = '\0';
			wrefresh((*win).win_info);
			wclear((*win).win_err);
			wrefresh((*win).win_err);
			break ;
		}
	}
	return (0);
}

int	main(void)
{
	char	w_list[TOTAL_WORDS + 1][6];
	char	after_list[TOTAL_WORDS + 1][6];
	char	*word = NULL;
	char	*color = NULL;
	int		i;
	int		guess = 1;
	t_win	win;

	initscr(); /*initiate ncurses window*/
	start_color(); /*start ncurses colors*/
	initiate_colors();
	initialize_window(&win);
	initialize_help_box(win);
	refresh_window(win);
	store_words(&w_list);
	w_list[TOTAL_WORDS][0] = '\0';
	if (!initializer(&word, &color))
		return (0);
	while (1)
	{
		mvwprintw(win.win_input, 1, 1, "Enter word: ");
		box(win.win_input, 0, 0);
		wrefresh(win.win_input);
		mvwgetstr(win.win_input, 1, 13, word);
		wclear(win.win_input);
		if (word[0] == '!' && word[1] == 'q') /*type !q to quit*/
			exit_bundle(&win, word, color);
		else if (word[0] == '!' && word[1] == 'r') /*type !r to restart*/
		{
			guess = 1;
			restart_prog(&win);
			store_words(&w_list);
			w_list[TOTAL_WORDS][0] = '\0';
		}
		else if (guess == 7) /*Check if 6 guesses has been made*/
			print_ui(&win, "6 Guesses has been made!");
		else if (word[5] != '\0' || strlen(word) < 5) /*Check that word is 5 char long*/
			print_ui(&win, "Word needs to be 5 characters long!");
		else
		{
			add_word(guess, win, word); /*Prtins word to main window*/
			refresh_window(win);
			if (check_color(&win, word, color, w_list, after_list) == 1) /*restart, if !r was typed in color input*/
			{
				guess = 1;
				restart_prog(&win);
				store_words(&w_list);
				w_list[TOTAL_WORDS][0] = '\0';
			}
			else
			{
				add_color(guess, win, color, word);
				box(win.win_input, 0, 0);
				refresh_window(win);
				wclear(win.win_input);
				guess++;
			}
		}
	}
	return (0);
}
