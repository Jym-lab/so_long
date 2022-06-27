/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:51:50 by yjoo              #+#    #+#             */
/*   Updated: 2022/06/24 16:51:50 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_img	img_init(void *mlx)
{
	t_img	ret;
	int		w;
	int		h;

	ret.ground = mlx_xpm_file_to_image(mlx, "xpm/ground.xpm", &w, &h);
	ret.player[LEFT] = mlx_xpm_file_to_image(mlx, "xpm/player_l.xpm", &w, &h);
	ret.player[RIGHT] = mlx_xpm_file_to_image(mlx, "xpm/player_r.xpm", &w, &h);
	ret.wall = mlx_xpm_file_to_image(mlx, "xpm/wall.xpm", &w, &h);
	ret.collec = mlx_xpm_file_to_image(mlx, "xpm/collec.xpm", &w, &h);
	ret.exit[CLOSE] = mlx_xpm_file_to_image(mlx, "xpm/close_exit.xpm", &w, &h);
	ret.exit[OPEN] = mlx_xpm_file_to_image(mlx, "xpm/open_exit.xpm", &w, &h);
	return (ret);
}

static void	ft_putimg(t_game *g, int x, int y)
{
	t_img	img;
	int		d;
	int		s;

	img = g->img;
	d = g->player_dir;
	s = g->exit_status;
	if (g->map_info[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->win, img.wall, x * 64, y * 64);
	if (g->map_info[y][x] == '0')
		mlx_put_image_to_window(g->mlx, g->win, img.ground, x * 64, y * 64);
	if (g->map_info[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, img.exit[s], x * 64, y * 64);
	if (g->map_info[y][x] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, img.player[d], x * 64, y * 64);
	if (g->map_info[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, img.collec, x * 64, y * 64);
}

void	img_update(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->cols && game->map_info[i])
	{
		j = 0;
		while (j < game->rows && game->map_info[i][j])
		{
			ft_putimg(game, j, i);
			j++;
		}
		i++;
	}
}
