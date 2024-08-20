/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:54:08 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/20 15:49:42 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 512
# define HEIGHT 512

# define SQUARE_SIZE 100

typedef struct s_mapvalues
{
	char	**layout;
	char	**testlayout;
	int		h;
	int		w;
	int		mov;
}			t_map;

typedef struct s_connections
{
	mlx_t	*mlxptr;
	t_map	map;
	char	*maparg;
}			t_con;

void		argument_check(char *argv[], int argc, t_con *prg);
int			ber_check(char *argv, t_con *prg);
t_map		get_map_values(char *map_file);

#endif
