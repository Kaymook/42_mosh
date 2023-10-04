/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 03:57:16 by mosh              #+#    #+#             */
/*   Updated: 2023/10/04 09:00:17 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int ft_printf(const char *format, ...)
{
	va_list ap;
	int i;
	char *s;
	va_start(ap, format);
	while (*format != '\0')
	{
		while (*format == '%')
			format++;
		if (format == 'c')
		{
			s = va_arg(ap, char);
			ft_putchar_fd(s);
		}
		else if (format == 's')
		{
			s = va_arg(ap, char *);
			ft_putstr_fd(s);
		}
		else if (format == 'p')
		{
		}
		else if (format == 'd')
		{
			i = va_arg(ap, int);
			ft_fdputnbr(i, 1);
		}
		else if (format == 'i')
		{
		}
		else if (format == 'u')
		{
		}
		else if (format == 'x')
		{
		}
		else if (format == 'X')
		{
		}
		format++;
	}
}
