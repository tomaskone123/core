/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:22:45 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/13 16:48:16 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int sig)
{
	printf("Caught a signal %d\n", sig);
	exit(0);
}

int	main(void)
{
	// if (argc != 3 || !(ft_strlen(argv[2])))
	// 	return (1);
	signal(SIGINT, handle_signal);
	ft_printf("Press CTRL+C to trigger SIGINT\n");
	while (1)
		sleep(1);
	return (0);
}
