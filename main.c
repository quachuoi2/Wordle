/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:07:55 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/24 07:44:46 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

void	store_words(char (*w_list)[TOTAL_WORDS + 1][6])
{
	int		fd;
	int		i;
	char	*s;

	fd = open("list_of_all", O_RDONLY);
	i = 0;
	while (get_next_line(fd, &s))
	{
		ft_strcpy((*w_list)[i], s);
		free(s);
		i++;
	}
	close(fd);
}

int	read_input(char **word, char **color)
{
	char	i;

	freer(word, color);
	if (!initializer(word, color))
		return (0);
	printf("---type '0' to stop---\nWord input: ");
	scanf("%s", *word);
	if ((*word)[0] == '0')
		return (0);
	printf("Color return: ");
	scanf("%s", *color);
	return (1);
}

int	main(void)
{
	char	w_list[TOTAL_WORDS + 1][6];
	char	after_list[TOTAL_WORDS + 1][6];
	char	*word;
	char	*color;
	int		i;

	store_words(&w_list);
	w_list[TOTAL_WORDS][0] = '\0';
	word = NULL;
	color = NULL;
	while (read_input(&word, &color))
	{
		check_word(&w_list, &after_list, word, color);
		i = 0;
		while (after_list[i][0] != '\0')
		{
			ft_strcpy(w_list[i], after_list[i]);
			printf("%s\n", after_list[i]);
			i++;
		}
		w_list[i][0] = '\0';
	}
	return (0);
}
