/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:54:08 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/05 14:31:42 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include <stdlib.h>
# include "MLX42/MLX42.h"

# define SQUARE_SIZE 100

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	ft_randomize(void *param);
void	ft_hook(void *param);



#endif
