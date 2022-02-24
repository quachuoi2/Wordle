/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:24:29 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/24 08:18:43 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int		check_gsy(char *possible_word, char *input_word, char *color)
{
	int	i;
	int	i2;
	int	present;

	i = 0;
	while (input_word[i])
	{
		if (color[i] == 'g')
			if ((possible_word[i] != input_word[i]))
				return (0);
		i2 = 0;
		present = 0;
		while (possible_word[i2])
		{
			if (color[i] == 's')
				if (possible_word[i2] == input_word[i] && color[i2] != 'g')
					return (0);
			if (color[i] == 'y')
				if (possible_word[i2] == input_word[i] && i != i2)
					present = 1;
			i2++;
		}
		if (present == 0 && color[i] == 'y')
			return (0);
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
		if (check_gsy((*w_list)[i], word, color))
			ft_strcpy((*after_list)[i2++], (*w_list)[i]);
		i++;
	}
	(*after_list)[i2][0] = '\0';
}
