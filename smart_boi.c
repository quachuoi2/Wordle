/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_boi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:57:25 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/25 05:26:50 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int	find_word(char (*list)[TOTAL_WORDS + 1][6], double (*value_list)[TOTAL_WORDS + 1], char *color)
{
	int		i;
	int		max_index;
	double	max;
	char	*test_color;

	i = 0;
	test_color = (char *)ft_memalloc(sizeof(char) * 6);
	while ((*list)[i][0] != '\0')
	{
		(*value_list)[i] = cal_total_word_value(list, (*list)[i], test_color);
		i++;
	}
	(*value_list)[i] = 0;
	max = 0;
	max_index = 0;
	while (i > 0)
	{
		if ((*value_list)[i] > max)
		{
			max = (*value_list)[i];
			max_index = i;
		}
		i--;
	}
	free(test_color);
	return (max_index);
}

double	cal_bit_value(char (*list)[TOTAL_WORDS + 1][6], char *word, char *color)
{
	int		i;
	int		total;
	double	probability;
	double	bit_val;

	i = 0;
	total = 0;
	while ((*list)[i][0] != '\0')
	{
		if (check_gsy((*list)[i], word, color))
			total++;
		i++;
	}
	probability = (double)total / (double)i;
	bit_val = log2(1.0 / probability);
	if (total > 0)
		return (probability * bit_val);
	return (0.000000000000);
}

double	cal_total_word_value(char (*list)[TOTAL_WORDS + 1][6], char *word, char *test_color)
{
	int		i;
	int		i2;
	int		i3;
	int		i4;
	int		i5;
	double	total;

	total = 0.0;
	i = 1;
	while (i < 4)
	{
		i2 = 1;
		while (i2 < 4)
		{
			i3 = 1;
			while (i3 < 4)
			{
				i4 = 1;
				while (i4 < 4)
				{
					i5 = 1;
					while (i5 < 4)
					{
						num_to_color(i, i2, i3, i4, i5, test_color);
						total += cal_bit_value(list, word, test_color);
						i5++;
					}
					i4++;
				}
				i3++;
			}
			i2++;
		}
		i++;
	}
	return (total);
}
