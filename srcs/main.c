/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 03:30:41 by yjoo              #+#    #+#             */
/*   Updated: 2022/06/23 05:19:16 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	exit_msg(char *str)
{
	printf("%s", str);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		i;

	if (ac != 2)
		exit_msg("./so_long [path/map.ber]\n");
	get_map(av[1], &game);
	return (0);
}
