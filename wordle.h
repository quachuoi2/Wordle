/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:36:25 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/25 05:40:05 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
# define WORDLE_H
# define TOTAL_WORDS 12972
# define FD_SIZE 4096
# define BUFF_SIZE 42
# define KBLU  "\x1B[34m"
# define KRED  "\x1B[31m"
# define KYEL  "\x1B[33m"
# define KNRM  "\x1B[0m"
# include "libft.h"
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <math.h>

int		get_next_line(const int fd, char **line);

/* utilities.c */
int		duplicate(char *s, char c);
int		word_color_mallocs(char **word, char **color);
void	freer(char **word, char **color);
void	color_to_num(char *s);
void	num_to_color(int i, int i2, int i3, int i4, int i5, char *s);
void	initializer(char (*s)[TOTAL_WORDS + 1][6]);
void	num_initializer(double (*s)[TOTAL_WORDS + 1]);
int		check_color(char *color);

/* check_functions.c */
void	check_word(char (*w_list)[TOTAL_WORDS + 1][6], char (*after_list)[TOTAL_WORDS + 1][6], char *word, char *color);
double	logbase(double y, int b);
int		check_gsy(char *possible_word, char *input_word, char *color);

/* smart_boi.c */
double	cal_bit_value(char (*w_list)[TOTAL_WORDS + 1][6], char *word, char *color);
double	cal_total_word_value(char (*w_list)[TOTAL_WORDS + 1][6], char *word, char *test_color);
int		find_word(char (*list)[TOTAL_WORDS + 1][6], double (*value_list)[TOTAL_WORDS + 1], char *color);

#endif
