/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:07:55 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/23 09:09:47 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*s;
	char	w_list[12972][6];

	fd = open("l_o_all", O_RDONLY);
	i = 0;
	while (get_next_line(fd, &s))
	{
		ft_strcpy(w_list[i], s);
		free(s);
		i++;
	}
	return (0);
}
