/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:get_next_line/get_next_line.h
/*   Created: 2023/10/16 21:24:22 by kmoshker          #+#    #+#             */
/*   Updated: 2023/10/17 16:42:58 by kmoshker         ###   ########.fr       */
=======
/*   Created: 2023/10/04 10:36:17 by kmoshker          #+#    #+#             */
/*   Updated: 2023/10/24 04:37:27 by kmoshker         ###   ########.fr       */
>>>>>>> for submittion 3 times:libft/ft_lstiter.c
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

<<<<<<< HEAD:get_next_line/get_next_line.h
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>
# include <>

char	*get_next_line(int fd);

#endif
=======
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
>>>>>>> for submittion 3 times:libft/ft_lstiter.c
