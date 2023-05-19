/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:15:57 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/23 18:36:46 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*p_src;
	char		*p_dst;
	size_t		x;

	p_src = (char *)src;
	p_dst = (char *)dst;
	x = -1;
	if (!src && !dst)
		return (NULL);
	if (p_src < p_dst)
	{
		while (len-- > 0)
			p_dst[len] = p_src[len];
	}
	else
	{
		while (++x < len)
			p_dst[x] = p_src[x];
	}
	return (dst);
}
