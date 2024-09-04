/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:51:42 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/04 14:45:07 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_con *prg, int new_x, int new_y)
{
	if ((prg->map.layout[new_x][new_y] != '1') && (prg->map.layout[new_x][new_y] != 'E'))
	{
		if (prg->map.layout[new_x][new_y] != 'C')
			prg->map.collectibles--;
		prg->map.layout[prg->map.px][prg->map.py] = '0';
		prg->map.layout[new_x][new_y] = 'P';
		prg->map.px = new_x;
		prg->map.py = new_y;
		prg->map.mov++;
		mlx_delete_image(prg->mlxptr, prg->images.player);
		draw_map(prg);
		ft_printf("x:%d\ny:%d\n", prg->map.px, prg->map.py);
	}
}
