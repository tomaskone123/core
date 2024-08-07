/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:36:48 by tomas             #+#    #+#             */
/*   Updated: 2024/06/06 13:54:13 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = c;
	if (cc == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (cc == *s)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
// int main(void)
// {
// 	char *s;
// 	const char *src = "teste";
// 	while (*src)
// 	{
// 		printf("src: %p\n", src);
// 		src++;
// 	}
// 	printf("last src: %p\n", src);
// 	s = ft_strchr(src, '\0');
// 	printf("%p\n", s);
// }
