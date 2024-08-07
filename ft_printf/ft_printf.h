/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:00:26 by tkonecny          #+#    #+#             */
/*   Updated: 2024/06/16 19:27:05 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

struct					s_convert
{
	char				*sym;
	int					(*f)(va_list);
};
typedef struct s_convert	t_convert;

typedef struct s_gvar
{
	int					string;
	int					function;
	int					i;
	int					end_value;
	int					chartotal;
	unsigned long long	remainder;
	unsigned long long	lint;
	int					b;
	unsigned int		uni;
	const char			*a;
	char				*hex;
	char				*result;
	void				*ptr;
}						t_variables;

int						ft_printf(const char *format, ...);
int						character_count(const char *format, va_list arg,
							t_convert f_list[]);
int						print_string(va_list arg);
int						print_char(va_list arg);
int						print_int(va_list arg);
int						print_unsigned(va_list arg);
int						print_low_hex(va_list arg);
int						print_upp_hex(va_list arg);
int						print_pointer(va_list arg);
char					*reverse_string(char *hex, int len);
int						make_hex(int remainder, unsigned long long lint,
							char *hex, const char *a);
char					*ft_utoa(unsigned int num);

#endif
