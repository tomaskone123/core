/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:54:08 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/04 14:43:44 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 542
# define HEIGHT 542

# define TILE_SIZE 90

typedef struct s_images
{
	mlx_image_t	*player;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*floor;
	mlx_image_t	*exit;

}				t_images;

typedef struct s_mapvalues
{
	int			x_load;
	int			y_load;
	char		**layout;
	char		**testlayout;
	int			h;
	int			w;
	int			mov;
	int			i;
	int			j;
	int			fd;
	int			ex;
	int			ey;
	int			px;
	int			py;
	int			player_count;
	int			collectibles;
	int			exits;
}				t_map;

typedef struct s_connections
{
	t_images	images;
	mlx_t		*mlxptr;
	t_map		map;
	char		*maparg;
}				t_con;

void			fdfail(void);
void			argument_check(char *argv[], int argc, t_con *prg);
int				ber_check(char *argv, t_con *prg);
t_map			get_map_values(char *map_file);
void			free_layout(char **layout);
void			so_long_exit(t_con *prg);
char			*load_line(char *line, char *layout, t_map *map1);
int				check_exits(char **layout, t_map *map);
int				check_collectibles(char **layout, t_map *map);
int				check_borders(char **layout, t_map map);
void			flood_fill(char **layout, int x, int y, t_map *map);
int				check_reachability(char **layout, t_map *map);
int				check_size(t_map *map);
void			load_images(t_con *prg);
void			draw_map(t_con *prg);
char			**initialize_textures(char** textures);
void			move_player(t_con *prg, int new_x, int new_y);

#endif
