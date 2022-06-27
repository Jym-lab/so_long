/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 01:28:50 by yjoo              #+#    #+#             */
/*   Updated: 2022/06/27 01:38:40 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include "../mlx/mlx.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
//# include "key_macos.h"
# include "key_linux.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"

# define MAP_EXT ".ber"
# define KEY_PRESS 2
# define DESTROY_NOTIFY 17

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*ground;
	void	*collec;
	void	*exit;
}		t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map_info;
	int		rows;
	int		cols;
	int		t_collec;
	t_img	img;
}		t_game;

void	get_map(char *filename, t_game *game);
void	map_check(t_game *game);
void	exit_msg(char *str);
void	img_update(t_game *game, void *mlx, void *win, t_img img);
void	w_event(t_game *game);
void	a_event(t_game *game);
void	s_event(t_game *game);
void	d_event(t_game *game);

t_img	img_init(void *mlx);

#endif
