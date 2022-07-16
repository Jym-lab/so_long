/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 03:30:41 by yjoo              #+#    #+#             */
/*   Updated: 2022/07/16 13:58:18 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_msg(char *str)
{
	printf("Error\n%s", str);
	exit(EXIT_FAILURE);
}

static void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->rows * 64,
			game->cols * 64, "so_long");
	game->img = img_init(game->mlx);
	game->collec_cnt = 0;
	game->walk_cnt = 0;
	game->player_dir = RIGHT;
	game->exit_status = CLOSE;
	img_update(game);
}

int	game_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

int	input_key(int keycode, t_game *game)
{
	if (keycode == K_W)
		w_event(game);
	else if (keycode == K_A)
		a_event(game);
	else if (keycode == K_S)
		s_event(game);
	else if (keycode == K_D)
		d_event(game);
	else if (keycode == K_ESC)
		game_exit(game);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		exit_msg("./so_long [path/map.ber]\n");
	get_map(av[1], &game);
	game_init(&game);
	mlx_hook(game.win, KEY_PRESS, 0, &input_key, &game);
	mlx_hook(game.win, DESTROY_NOTIFY, 0, &game_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}
