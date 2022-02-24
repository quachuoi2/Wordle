/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:24:29 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/24 07:37:30 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int		check_green(char *possible_word, char *input_word, char *color)
{
	int	i;

	i = 0;
	while (possible_word[i])
	{
		if (color[i] == 'g')
			if ((possible_word[i] != input_word[i]))
				return (0);
		i++;
	}
	return (1);
}

int		check_silver(char *possible_word, char *input_word, char *color)
{
	int	i;
	int	i2;

	i = 0;
	while (input_word[i])
	{
		i2 = 0;
		if (color[i] == 's')
		{
			while (possible_word[i2])
			{
				if (possible_word[i2] == input_word[i] && color[i2] != 'g')
					return (0);
				i2++;
			}
		}
		i++;
	}
	return (1);
}

int		check_yellow(char *possible_word, char *input_word, char *color)
{
	int	i;
	int	i2;
	int	present;

	i = 0;
	while (input_word[i])
	{
		i2 = 0;
		if (color[i] == 'y')
		{
			while (possible_word[i2])
			{
				if (possible_word[i2] == input_word[i] && i != i2)
					present = 1;
				i2++;
			}
			if (present == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

void	check_word(char (*w_list)[TOTAL_WORDS + 1][6], char (*after_list)[TOTAL_WORDS + 1][6], char *word, char *color)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while ((*w_list)[i][0] != '\0')
	{
		if (check_green((*w_list)[i], word, color)
			&& check_silver((*w_list)[i], word, color)
			&& check_yellow((*w_list)[i], word, color))
			ft_strcpy((*after_list)[i2++], (*w_list)[i]);
		i++;
	}
	(*after_list)[i2][0] = '\0';
}
