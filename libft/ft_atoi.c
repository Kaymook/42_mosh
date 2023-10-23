/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:15:05 by kmoshker          #+#    #+#             */
/*   Updated: 2023/09/30 22:33:00 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					minus;
	unsigned long long	num;

	num = 0;
	minus = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if (minus == 1 && (num > LONG_MAX / 10
				|| (num == LONG_MAX / 10 && 7 <= *str - '0')))
			return ((int)LONG_MAX);
		if (minus == -1 && ((num >= LONG_MAX / 10 && (8 <= *str - '0'))))
			return ((int)LONG_MIN);
		num = num * 10 + (*str - '0');
		str++;
	}
	return ((int)(num * minus));
}

// int	ft_atoi(const char *str)
// {
// 	int					minus;
// 	unsigned long long	num;
// 	num = 0;
// 	minus = 1;
// 	while ((9 <= *str && *str <= 13) || *str == 32)
// 		str++;
// 	if (*str == '-')
// 		minus = -1;
// 	if (*str == '-' || *str == '+')
// 		str++;
// 	while ('0' <= *str && *str <= '9')
// 	{
//   		if (minus == 1 && (num > LONG_MAX / 10
// 				|| (num == LONG_MAX / 10 && 7 <= *str - '0')))
// 		{
// 			//printf("%d\n", *str - '0');
// 			return ((int)LONG_MAX);
// 		}
// 		if (minus == -1 && ((num >= LONG_MAX / 10 && (8 <= *str - '0'))))
// 			//(minus == -1 && ((num >= (unsind long long)(-LONG_MIN)
// 				//  / 10 && (8 <= *str - '0'))))
// 			return ((int)LONG_MIN);
// 		num = num * 10 + (*str - '0');
// 		//printf("%llu\n", num);
// 		str++;
// 	}
// 	//printf("ft_atoi  :  %d\n\n", (int)(num * minus));
// 	return ((int)(num * minus));
// }