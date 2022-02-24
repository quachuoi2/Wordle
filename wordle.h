/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:36:25 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/24 15:43:25 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
# define WORDLE_H
# define TOTAL_WORDS 12972
# define FD_SIZE 4096
# define BUFF_SIZE 42
# define GREEN	1
# define YELLOW	2
# define WHITE	3
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <ncurses.h>
# include <string.h> 

typedef struct s_win
{
	WINDOW *win[30];
	WINDOW *win_input;
	WINDOW *win_err;
	WINDOW *win_main;
	WINDOW *win_info;
	WINDOW *win_help;
}	t_win;

int		get_next_line(const int fd, char **line);
int		duplicate(char *s, char c);
void	check_word(char w_list[TOTAL_WORDS + 1][6], char after_list[TOTAL_WORDS + 1][6], char *word, char *color);
int		initializer(char **word, char **color);
void	freer(char **word, char **color);

/*window.c*/

void	initialize_window(t_win *win);
void	refresh_window(t_win win);
void	clear_window(t_win win);
void	add_word(int c, t_win win, char *str);
void	add_color(int c, t_win win, char *color, char *str);
int		check_color_input(char* color);
void	initiate_colors();
void	initialize_help_box(t_win win);

#endif
