/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 06:57:09 by mosh              #+#    #+#             */
/*   Updated: 2023/10/24 06:57:11 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	 ft_strlen(const char *s)
{
	int	 len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*ft_strcpy(char *dst, const char *src)
{
	int		count;
	int		i;

	count = ft_strlen(src);
	i = 0;
	while (count > i)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


char *ft_strcat(char *dst, const char *src)
{
	int num1;
	int	 i;

	num1 = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0')
	{
		dst[num1 + i] = src[i];
		i++;
	}
	dst[num1 + i] = '\0';
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*new;

	if (!s1)
		return (NULL);
	new = (char *)malloc((ft_strlen(s1) + 1) * (sizeof(char)));
	if (!new)
		return (NULL);
	ft_strcpy(new, s1);
	return (new);
}
