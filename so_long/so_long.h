/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:54:08 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/08 13:28:54 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./lib/libft/libft.h"
# include "./lib/MLX42/include/MLX42/MLX42.h"

# define WIDTH 512
# define HEIGHT 512

# define SQUARE_SIZE 100

typedef struct s_connections
{
	mlx_t	mlxptr;
	char	*maparg;
}	t_con;

void	argument_check(char* argv[], int argc);

#endif
