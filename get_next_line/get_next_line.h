/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:24:22 by kmoshker          #+#    #+#             */
/*   Updated: 2023/10/24 07:01:11 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*develop_remember_me(char *remember_me, int fd);
char	*output_line_until(char *remember_me);
char	*delete_and_renew(char *remember_me);
char	*ft_strchr(const char *s, int c);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strjoin(char *s1, char *s2);
int 	ft_strlen(const char *s);
char	*ft_strdup(char *s1);

#endif