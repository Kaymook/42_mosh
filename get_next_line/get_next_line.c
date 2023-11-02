/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:25:52 by kmoshker          #+#    #+#             */
/*   Updated: 2023/11/02 19:19:43 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;

	if (!s1 && !s2)
	{
		free (s1);
		return (NULL);
	}
	else if (!s1)
	{
		free (s1);
		return (ft_strdup(s2));
	}
	else if (!s2)
		return (ft_strdup(s1));
	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	new[0] = '\0';
	ft_strcat(new, s1);
	ft_strcat(new, s2);
	free (s1);
	return (new);
}

char	*develop_remember_me(char *remember_me, int fd)
{
	char	develop[BUFFER_SIZE + 1];
	int		bytes_to_read;

	bytes_to_read = 1;
	while (bytes_to_read > 0 && !ft_strchr(remember_me, '\n'))
	{
		bytes_to_read = read(fd, develop, BUFFER_SIZE);
		if (bytes_to_read <= -1)
			return (NULL);
		if (bytes_to_read == 0 && (!remember_me
				|| ft_strlen(remember_me) == 0))
		{
			if (remember_me)
				free(remember_me);
			return (NULL);
		}
		develop[bytes_to_read] = '\0';
		remember_me = ft_strjoin(remember_me, develop);
	}
	return (remember_me);
}

char	*output_line_until(char *remember_me)
{
	int		i;
	char	*output_line;

	i = 0;
	if (!remember_me)
		return (NULL);
	while (remember_me[i] && remember_me[i] != '\n')
		i++;
	output_line = malloc(sizeof(char) * (i + 2));
	if (!output_line)
		return (NULL);
	i = 0;
	while (remember_me[i] && remember_me[i] != '\n')
	{
		output_line[i] = remember_me[i];
		i++;
	}
	if (remember_me[i] == '\n')
		output_line[i] = remember_me[i];
	output_line[i + 1] = '\0';
	return (output_line);
}

char	*delete_and_renew(char *remember_me)
{
	int		i;
	int		j;
	char	*forget_me;

	i = 0;
	while (remember_me[i] && remember_me[i] != '\n')
		i++;
	if (remember_me[i] == '\n')
		i++;
	forget_me = malloc(sizeof(char) * (ft_strlen(remember_me) - i + 1));
	if (!forget_me)
		return (NULL);
	j = 0;
	while (remember_me[i])
		forget_me[j++] = remember_me[i++];
	forget_me[j] = '\0';
	free (remember_me);
	if (ft_strlen(forget_me) == 0)
	{
		free (forget_me);
		return (NULL);
	}
	return (forget_me);
}

char	*get_next_line(int fd)
{
	static char	*remember_me;
	char		*output_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	remember_me = develop_remember_me(remember_me, fd);
	if (!remember_me || ft_strlen(remember_me) == 0)
	{
		free (remember_me);
		return (NULL);
	}
	output_line = output_line_until(remember_me);
	remember_me = delete_and_renew(remember_me);
	return (output_line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main(int argc, char **argv)
// {
//     int fd;
//     char *line;

//     if (argc != 2)
//     {
//         printf("Usage: %s <filename>\n", argv[0]);
//         return (1);
//     }

//     fd = open(argv[1], O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s\n", line);
//         free(line);
//     }

//     close(fd);
//     return (0);
// }