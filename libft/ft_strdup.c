/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:34:24 by kmoshker          #+#    #+#             */
/*   Updated: 2023/10/18 03:49:33 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
