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

static void	find_player(t_game *game, int *i, int *j)
{
	while (*i < game->cols && game->map_info[*i])
	{
		*j = 0;
		while (*j < game->rows && game->map_info[*i][*j])
		{
			if (game->map_info[*i][*j] == 'P')
				return ;
			*j += 1;
		}
		*i += 1;
	}
}

void	w_event(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	find_player(game, &i, &j);
	if (game->map_info[i - 1][j] != '1' && game->map_info[i - 1][j] != 'E')
	{
		if (game->map_info[i - 1][j] == 'C')
		{
			game->collec_cnt++;
			if (game->t_collec == game->collec_cnt)
				game->exit_status = OPEN;
		}
		game->map_info[i][j] = '0';
		game->map_info[i - 1][j] = 'P';
		game->walk_cnt++;
		img_update(game);
		printf("walk : %d\n", game->walk_cnt);
	}
	if (game->map_info[i - 1][j] == 'E')
	{
		if (game->t_collec == game->collec_cnt)
			game_exit(game);
	}
}

void	a_event(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	find_player(game, &i, &j);
	if (game->map_info[i][j - 1] != '1' && game->map_info[i][j - 1] != 'E')
	{
		if (game->map_info[i][j - 1] == 'C')
		{
			game->collec_cnt++;
			if (game->t_collec == game->collec_cnt)
				game->exit_status = OPEN;
		}
		game->map_info[i][j] = '0';
		game->map_info[i][j - 1] = 'P';
		game->walk_cnt++;
		game->player_dir = LEFT;
		img_update(game);
		printf("walk : %d\n", game->walk_cnt);
	}
	if (game->map_info[i][j - 1] == 'E')
	{
		if (game->t_collec == game->collec_cnt)
			game_exit(game);
	}
}

void	s_event(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	find_player(game, &i, &j);
	if (game->map_info[i + 1][j] != '1' && game->map_info[i + 1][j] != 'E')
	{
		if (game->map_info[i + 1][j] == 'C')
		{
			game->collec_cnt++;
			if (game->t_collec == game->collec_cnt)
				game->exit_status = OPEN;
		}
		game->map_info[i][j] = '0';
		game->map_info[i + 1][j] = 'P';
		game->walk_cnt++;
		img_update(game);
		printf("walk : %d\n", game->walk_cnt);
	}
	if (game->map_info[i + 1][j] == 'E')
	{
		if (game->t_collec == game->collec_cnt)
			game_exit(game);
	}
}

void	d_event(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	find_player(game, &i, &j);
	if (game->map_info[i][j + 1] != '1' && game->map_info[i][j + 1] != 'E')
	{
		if (game->map_info[i][j + 1] == 'C')
		{
			game->collec_cnt++;
			if (game->t_collec == game->collec_cnt)
				game->exit_status = OPEN;
		}
		game->map_info[i][j] = '0';
		game->map_info[i][j + 1] = 'P';
		game->walk_cnt++;
		game->player_dir = RIGHT;
		img_update(game);
		printf("walk : %d\n", game->walk_cnt);
	}
	if (game->map_info[i][j + 1] == 'E')
	{
		if (game->t_collec == game->collec_cnt)
			game_exit(game);
	}
}
