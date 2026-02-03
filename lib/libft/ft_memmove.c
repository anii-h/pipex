/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:35:38 by anihamba          #+#    #+#             */
/*   Updated: 2025/02/13 19:31:36 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;

	dest = dst;
	source = src;
	if (dst == NULL && src == NULL)
		return (dst);
	if (dest > source && dest < source + len)
		while (len--)
			dest[len] = source[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>

int main(void)
{
	char src[10] = "to cpy";
	char mine[10] = "12";
	char cmp[10] = "12";
	printf("%s\n", ft_memmove(mine, src, 3));
	printf("%s\n", memmove(cmp, src, 3));
}*/
