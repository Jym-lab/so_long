/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 02:17:57 by yjoo              #+#    #+#             */
/*   Updated: 2022/06/24 02:26:14 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ext_check(char *filename, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(filename) - ft_strlen(ext);
	if (filename[i] != '.' || i <= 0)
		return (0);
	j = 0;
	while (filename[i + j] && ext[j])
	{
		if (filename[i + j] == ext[j])
			j++;
		else
			return (0);
	}
	if (filename[i + j] != '\0' && ext[j] != '\0')
		return (0);
	return (1);
}

static void	open_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		exit_msg("Failed to open file\n");
	tmp = NULL;
	line = get_next_line(fd);
	game->rows = ft_strlen(line) - 1;
	game->cols = 0;
	tmp = gnl_ft_strjoin(tmp, line);
	free(line);
	while (line)
	{
		game->cols++;
		line = get_next_line(fd);
		if (line)
			tmp = gnl_ft_strjoin(tmp, line);
		free(line);
	}
	game->map_info = ft_split(tmp, '\n');
	free(tmp);
}

void	get_map(char *filename, t_game *game)
{
	if (!ext_check(filename, MAP_EXT))
		exit_msg("Wrong extension check the extension\n");
	open_map(filename, game);
	map_check(game);
}
