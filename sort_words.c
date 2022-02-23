/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:11:09 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/23 09:12:34 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"
//compile this as main file to combine poss and words into one sorted file

void	ft_swapstr(char *str, char *str2)
{
	char	c[6];

	ft_strcpy(c, str);
	ft_strcpy(str, str2);
	ft_strcpy(str2, c);
}

int	main(void)
{
	int		fd;
	int		i;
	int		i2;
	char	*s;
	char	w_list[12972][6];

	fd = open("l_o_poss", O_RDONLY);
	i = 0;
	while (get_next_line(fd, &s))
	{
		ft_strcpy(w_list[i], s);
		free(s);
		i++;
	}
	fd = open("l_o_words", O_RDONLY);
	while (get_next_line(fd, &s))
	{
		ft_strcpy(w_list[i], s);
		free(s);
		i++;
	}
	i = 0;
	while (i < 12971)
	{
		i2 = i + 1;
		while (i2 < 12972)
		{
			if (ft_strcmp(w_list[i], w_list[i2]) > 0)
				ft_swapstr(w_list[i], w_list[i2]);
			i2++;
		}
		i++;
	}
	i = 0;
	while (i < 12972)
	{
		printf("%s\n", w_list[i]);
		i++;
	}
}
