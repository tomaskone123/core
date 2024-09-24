/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:22:45 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/23 15:40:41 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_isnum(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '-')
		i++;
	while (c[i])
	{
		if (!ft_isdigit(c[i]))
			return (0);
		i++;
	}
	return (1);
}

void	send_signal(pid_t server_pid, char message)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((message >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(1000);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*message;

	if (argc != 3 || !(ft_strlen(argv[2])) || !(ft_isnum(argv[1])))
	{
		ft_printf("Error\n");
		ft_printf("Usage: ./client [Server PID] [message]\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	while (*message)
	{
		send_signal(server_pid, *message);
		message++;
	}
	return (0);
}
