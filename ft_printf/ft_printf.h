/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:15:51 by mosh              #+#    #+#             */
/*   Updated: 2023/10/14 23:09:22 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *s);
size_t ft_putchar_fd(int c, int fd);
size_t ft_putstr_fd(char *str, int fd);
size_t ft_putptr_fd(uintptr_t ptr, int fd);
size_t ft_puthex_small(unsigned int num);
size_t ft_puthex_big(unsigned int num);
size_t ft_put_unsigned_nbr(unsigned int n);
size_t ft_putnbr_fd(int n, int fd);
int ft_printf(const char *format, ...);

#endif