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
	int		wid;
	int		hei;

	ret.ground = mlx_xpm_file_to_image(mlx, "xpm/ground.xpm", &wid, &hei);
	ret.player = mlx_xpm_file_to_image(mlx, "xpm/player.xpm", &wid, &hei);
	ret.wall = mlx_xpm_file_to_image(mlx, "xpm/wall.xpm", &wid, &hei);
	ret.collec = mlx_xpm_file_to_image(mlx, "xpm/collec.xpm", &wid, &hei);
	ret.exit = mlx_xpm_file_to_image(mlx, "xpm/exit.xpm", &wid, &hei);
	return (ret);
}

void	img_update(t_game *game, void *mlx, void *win, t_img img)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->cols && game->map_info[i])
	{
		j = 0;
		while (j < game->rows && game->map_info[i][j])
		{
			if (game->map_info[i][j] == '1')
				mlx_put_image_to_window(mlx, win, img.wall, j * 64, i * 64);
			if (game->map_info[i][j] == '0')
				mlx_put_image_to_window(mlx, win, img.ground, j * 64, i * 64);
			if (game->map_info[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, img.exit, j * 64, i * 64);
			if (game->map_info[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, img.player, j * 64, i * 64);
			if (game->map_info[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, img.collec, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
