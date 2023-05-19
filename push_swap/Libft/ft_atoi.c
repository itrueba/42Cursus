/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:22:15 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/10 12:08:22 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char *nptr)
{
	int				sign;
	long long int	result;

	sign = 1;
	result = 0;
	while (*nptr && (*nptr == ' ' || *nptr == '\n' || *nptr == '\t'
			|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r'))
		++nptr;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		++nptr;
		if (!ft_isdigit(*nptr))
			return (0);
	}
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			return (0);
		result = result * 10 + (*nptr - 48);
		++nptr;
	}
	return (result * sign);
}
