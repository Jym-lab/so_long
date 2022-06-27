/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 02:26:22 by yjoo              #+#    #+#             */
/*   Updated: 2022/06/24 02:26:22 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	border_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->cols && game->map_info[i])
	{
		j = 0;
		while (j < game->rows && game->map_info[i][j])
		{
			if (i == 0 || i == (game->cols - 1))
			{
				if (game->map_info[i][j] != '1')
					return (0);
			}
			else if (j == 0 || j == (game->rows - 1))
			{
				if (game->map_info[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	rect_check(t_game *game)
{
	int	i;
	int	map_len;

	i = 0;
	map_len = 0;
	while (i < game->cols)
	{
		map_len += ft_strlen(game->map_info[i]);
		i++;
	}
	if ((game->cols * game->rows) != map_len)
		return (0);
	return (1);
}

static int	param_check(t_game *game)
{
	int	i;
	int	j;
	int	e_cnt;
	int	p_cnt;

	i = -1;
	e_cnt = 0;
	p_cnt = 0;
	game->t_collec = 0;
	while (++i < game->cols && game->map_info[i])
	{
		j = -1;
		while (++j < game->rows && game->map_info[i][j])
		{
			if (game->map_info[i][j] == 'E')
				e_cnt++;
			else if (game->map_info[i][j] == 'P')
				p_cnt++;
			else if (game->map_info[i][j] == 'C')
				game->t_collec++;
		}
	}
	if (e_cnt == 0 || game->t_collec == 0 || p_cnt != 1)
		return (0);
	return (1);
}

void	map_check(t_game *game)
{
	int		err_cnt;
	char	*err_msg;

	err_cnt = 0;
	err_msg = NULL;
	if (!rect_check(game))
	{
		err_msg = gnl_ft_strjoin(err_msg, "map should be rectangular\n");
		err_cnt++;
	}
	if (!border_check(game))
	{
		err_msg = gnl_ft_strjoin(err_msg, "map should be surrounded by walls\n");
		err_cnt++;
	}
	if (!param_check(game))
	{
		err_msg = gnl_ft_strjoin(err_msg, "The map value is wrong.\n");
		err_cnt++;
	}
	if (err_cnt > 0)
		exit_msg(err_msg);
}
