/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:20:11 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/24 06:52:04 by qnguyen          ###   ########.fr       */
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
