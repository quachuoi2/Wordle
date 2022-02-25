/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:07:55 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/25 05:43:29 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

void	store_words(char (*w_list)[TOTAL_WORDS + 1][6])
{
	int		fd;
	int		i;
	char	*s;

	fd = open("list_of_actual_words", O_RDONLY);
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

	if (*word || *color)
		freer(word, color);
	if (!word_color_mallocs(word, color))
		return (0);
	printf("---type '0' to stop---\nWord input: ");
	scanf("%s", *word);
	if ((*word)[0] == '0')
		return (0);
	printf("Color return: ");
	scanf("%s", *color);
	if (check_color(*color) == 0)
		return (0);
	color_to_num(*color);
	return (1);
}

int	main(void)
{
	char	w_list[TOTAL_WORDS + 1][6];
	char	after_list[TOTAL_WORDS + 1][6];
	double	value_list[TOTAL_WORDS + 1];
	char	*word;
	char	*color;
	int		i;
	int		choice;
	int		count_down;

	initializer(&w_list);
	initializer(&after_list);
	num_initializer(&value_list);
	store_words(&w_list);
	word = NULL;
	color = NULL;
	printf("%stry %ssalet%s as the first guess if you will%s\n", KBLU, KYEL, KBLU, KNRM);
	count_down = 6;
	while (count_down > 0 && read_input(&word, &color))
	{
		check_word(&w_list, &after_list, word, color);
		choice = find_word(&after_list, &value_list, color);
		if (after_list[choice][0] == '\0')
		{
			printf("%sOh what?? Was the input correct?\nIf so, whoops my bad :D%s\n", KBLU, KNRM);
			break ;
		}
		else if (choice < 2)
			printf("%sIt's probably %s%s%s or %s%s%s\nTry %s%s%s\n", KBLU, KYEL, after_list[0], KBLU, KYEL, after_list[1], KBLU, KYEL, after_list[choice], KNRM);
		else
			printf("%sPerhaps try %s%s%s\n", KBLU, KYEL, after_list[choice], KNRM);
		i = -1;
		while (after_list[++i][0] != '\0')
			ft_strcpy(w_list[i], after_list[i]);
		w_list[i][0] = '\0';
		count_down--;
	}
	freer(&word, &color);
	return (0);
}
