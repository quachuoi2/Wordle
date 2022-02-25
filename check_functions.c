/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:24:29 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/25 05:45:07 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int	check_gsy(char *possible_word, char *input_word, char *color)
{
	int		i;
	int		i2;
	int		present;
	char	possible_dup[6];

	ft_strcpy(possible_dup, possible_word);
	i = 0;
	while (input_word[i])
	{
		if (color[i] == 1)
			if ((possible_dup[i] != input_word[i]))
				return (0);
		i2 = 0;
		present = 0;
		while (possible_dup[i2])
		{
			if (color[i] == 2)
				if (possible_dup[i2] == input_word[i] && color[i2] != 1)
					return (0);
			if (color[i] == 3)
			{
				if (possible_dup[i2] == input_word[i2])
					return (0);
				if (possible_dup[i2] == input_word[i] && i != i2 && present == 0)
				{
					present = 1;
					possible_dup[i2] = -1;
				}
			}
			i2++;
		}
		if (present == 0 && color[i] == 3)
			return (0);
		i++;
	}
	return (1);
}

void	check_word(char (*w_list)[TOTAL_WORDS + 1][6], char (*after_list)[TOTAL_WORDS + 1][6], char *word, char *color)
{
	int	i;
	int	i2;
	int	print_count;

	i = 0;
	i2 = 0;
	print_count = 0;
	printf("\n");
	while ((*w_list)[i][0] != '\0')
	{
		if (check_gsy((*w_list)[i], word, color))
		{
			ft_strcpy((*after_list)[i2], (*w_list)[i]);
			printf("%s   ", (*after_list)[i2]);
			if (print_count == 9)
			{
				printf("\n");
				print_count = -1;
			}
			print_count++;
			i2++;
		}
		i++;
	}
	(*after_list)[i2][0] = '\0';
	printf("\n\n");
}
