/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:25:52 by kmoshker          #+#    #+#             */
/*   Updated: 2023/10/17 19:16:44 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remember_me;
	char		buffer[BUFFER_SIZE + 1];
	char		*copy;
	ssize_t		bytes_read;
	ssize_t		i;

	if (remember_me && ft_strchr(remember_me, '\n'))
	{
		//remember_meのロジックの追加
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	copy = (char *)malloc((sizeof (char)) * (BUFFER_SIZE + 1));
	if (!copy)
		return (NULL);
	while (bytes_read > 0)
	{
		i = 0;
		buffer[bytes_read] = '\0';
		while (buffer[i++] != '\0')
		{
			if (buffer[i] != '\n')
			{
				copy[i] = buffer[i];
			}
			else
			{
				buffer[i] = '\0';
				return (copy);
			}
		}
	}
	// free 解放する
	return (NULL);
}

static char	*ft_strcat(char *dst, const char *src)
{
	int				num1;
	int				num2;
	size_t			i;

	num1 = ft_strlen(dst);
	num2 = ft_strlen(src);
	i = 0;
	while (src[i] != '\0')
	{
		dst[num1 + i] = src[i];
		i++;
	}
	dst[num1 + i] = '\0';
	return (dst);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	int		len1;
	int		len2;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else
		(ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
		new[i++] = *s1++;
	new[i] = '\0';
	ft_strcat(new, s2);
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	char	*new_2;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
	{
		new = (char *)malloc(1 * sizeof(char));
		if (!new)
			return (NULL);
		*new = '\0';
		return (new);
	}
	if (ft_strlen(s) < len)
		len = ft_strlen(s) - start;
	new = malloc((len + 1) * (sizeof(char)));
	if (!new)
		return (NULL);
	new_2 = new;
	while (len-- > 0 && s[start])
		*new_2++ = s[start++];
	*new_2 = '\0';
	return (new);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

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
	size_t	count;
	size_t	i;

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

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		count;

	if (!s1)
		return (NULL);
	count = ft_strlen(s1);
	new = (char *)malloc((count + 1) * (sizeof(char)));
	if (new == NULL)
		return (NULL);
	ft_strcpy(new, s1);
	return (new);
}
