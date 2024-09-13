/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:02:13 by tomas             #+#    #+#             */
/*   Updated: 2024/06/07 16:58:59 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <aio.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	ssize_t	result;

	result = write(fd, &c, 1);
}
