#ifndef SO_LONG_H
#define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"

#define MAP_EXT ".ber"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		rows;
	int		cols;
	char	**map_info;
}		t_game;


void	get_map(char *filename, t_game *game);
void	exit_msg(char *str);
void	free_split(char **split);

#endif
