/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:36:25 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/24 07:45:46 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
# define WORDLE_H
# define TOTAL_WORDS 12972
# define FD_SIZE 4096
# define BUFF_SIZE 42
# include "libft.h"
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>

int		get_next_line(const int fd, char **line);
int		duplicate(char *s, char c);
void	check_word(char (*w_list)[TOTAL_WORDS + 1][6], char (*after_list)[TOTAL_WORDS + 1][6], char *word, char *color);
int		initializer(char **word, char **color);
void	freer(char **word, char **color);

#endif
