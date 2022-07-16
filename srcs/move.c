/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:00:26 by yjoo              #+#    #+#             */
/*   Updated: 2022/07/16 13:29:20 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move(t_game *game, int i, int j)
{
	if (game->map_info[i][j] == 'C')
	{
		game->collec_cnt++;
		if (game->t_collec == game->collec_cnt)
			game->exit_status = OPEN;
	}
	game->map_info[i][j] = 'P';
	game->walk_cnt++;
	printf("walk : %d\n", game->walk_cnt);
}
