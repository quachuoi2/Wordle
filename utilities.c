/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:20:11 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/24 16:57:51 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int		duplicate(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int		initializer(char **word, char **color)
{
	*word = ft_memalloc(sizeof(char) * 6);
	*color = ft_memalloc(sizeof(char) * 6);
	if (!*word || !*color)
		return (0);
	return (1);
}

void	freer(char **word, char **color)
{
	if (word || color)
	{
		free(*word);
		free(*color);
	}
}

void	print_ui(t_win *win, char *s)
{
	mvwprintw((*win).win_err, 0, 1, s);
	wrefresh((*win).win_err);
}

void	exit_bundle(t_win *win, char *word, char *color)
{
	clear_window(*win);
	endwin();
	freer(&word, &color);
	exit(0);
}
