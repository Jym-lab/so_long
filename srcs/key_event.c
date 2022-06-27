/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 01:36:17 by yjoo              #+#    #+#             */
/*   Updated: 2022/06/27 01:36:17 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	w_event(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->cols && game->map_info[i])
	{
		j = 0;
		while (j < game->rows && game->map_info[i][j])
		{
			if (game->map_info[i][j] == 'P')
				break ;
			j++;
		}
		if (game->map_info[i][j] == 'P')
			break ;
		i++;
	}
	if (game->map_info[i - 1][j] != '1' && game->map_info[i - 1][j] != 'E')
	{
		game->map_info[i][j] = '0';
		game->map_info[i - 1][j] = 'P';
		img_update(game, game->mlx, game->win, game->img);
	}
}

void	a_event(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->cols && game->map_info[i])
	{
		j = 0;
		while (j < game->rows && game->map_info[i][j])
		{
			if (game->map_info[i][j] == 'P')
				break ;
			j++;
		}
		if (game->map_info[i][j] == 'P')
			break ;
		i++;
	}
	if (game->map_info[i][j - 1] != '1' && game->map_info[i][j - 1] != 'E')
	{
		game->map_info[i][j] = '0';
		game->map_info[i][j - 1] = 'P';
		img_update(game, game->mlx, game->win, game->img);
	}
}

void	s_event(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->cols && game->map_info[i])
	{
		j = 0;
		while (j < game->rows && game->map_info[i][j])
		{
			if (game->map_info[i][j] == 'P')
				break ;
			j++;
		}
		if (game->map_info[i][j] == 'P')
			break ;
		i++;
	}
	if (game->map_info[i + 1][j] != '1' && game->map_info[i + 1][j] != 'E')
	{
		game->map_info[i][j] = '0';
		game->map_info[i + 1][j] = 'P';
		img_update(game, game->mlx, game->win, game->img);
	}
}

void	d_event(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->cols && game->map_info[i])
	{
		j = 0;
		while (j < game->rows && game->map_info[i][j])
		{
			if (game->map_info[i][j] == 'P')
				break ;
			j++;
		}
		if (game->map_info[i][j] == 'P')
			break ;
		i++;
	}
	if (game->map_info[i][j + 1] != '1' && game->map_info[i][j + 1] != 'E')
	{
		game->map_info[i][j] = '0';
		game->map_info[i][j + 1] = 'P';
		img_update(game, game->mlx, game->win, game->img);
	}
}
