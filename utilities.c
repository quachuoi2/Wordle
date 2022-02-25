/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:20:11 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/25 05:39:20 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int	duplicate(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	word_color_mallocs(char **word, char **color)
{
	*word = ft_memalloc(sizeof(char) * 6);
	*color = ft_memalloc(sizeof(char) * 6);
	if (!*word || !*color)
		return (0);
	return (1);
}

void	initializer(char (*s)[TOTAL_WORDS + 1][6])
{
	int	i;
	int	i2;

	i = 0;
	while (i < TOTAL_WORDS + 1)
	{
		i2 = 0;
		while (i2 < 6)
		{
			(*s)[i][i2] = '\0';
			i2++;
		}
		i++;
	}
}

void	num_initializer(double (*s)[TOTAL_WORDS + 1])
{
	int	i;

	i = 0;
	while (i < TOTAL_WORDS + 1)
	{
		(*s)[i] = 0.0;
		i++;
	}
}

void	freer(char **word, char **color)
{
	free(*word);
	free(*color);
}

void	color_to_num(char *s)
{
	while (*s)
	{
		if (*s == 'g')
			*s = 1;
		else if (*s == 's')
			*s = 2;
		else if (*s == 'y')
			*s = 3;
		s++;
	}
}

void	num_to_color(int i, int i2, int i3, int i4, int i5, char *s)
{
	s[0] = i;
	s[1] = i2;
	s[2] = i3;
	s[3] = i4;
	s[4] = i5;
}

int	check_color(char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if ((color[i] != 'g' && color[i] != 'y' && color[i] != 's') || color[5] != '\0' || ft_strlen(color) < 5)
		{
			free(color);
			color = (char *)ft_memalloc(sizeof(char) * 6);
			printf("%sInvalid color. 'g' for  correct letter and position, 'y' for correct letter, wrong postion, 's' for letter doesn't exists.%s\nColor return: ", KRED, KNRM);
			scanf("%s", color);
			i = -1;
		}
		else if (color[0] == '0')
			return (0);
		else if (ft_strcmp(color, "ggggg") == 0)
		{
			printf("%sBIG NAIS!%s\n", KBLU, KNRM);
			return (0);
		}
		i++;
	}
	return (1);
}
