/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:52:18 by anihamba          #+#    #+#             */
/*   Updated: 2025/02/08 17:34:04 by ani              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	src_len = 0;
	dst_len = 0;
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	while (src[src_len] && src_len + dst_len + 1 < dstsize)
	{
		dst[dst_len + src_len] = src[src_len];
		src_len++;
	}
	if (dst_len < dstsize)
		dst[dst_len + src_len] = '\0';
	return (dst_len + ft_strlen(src));
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char str1[100] = "mine";
	char src[100] = "loop";
	char str2[100] = "original";
	printf("%lu", strlcat("pqrstuvwxyz", "abcd", 0));
	printf("\n%lu", ft_strlcat("pqrstuvwxyz", "abcd", 0));
}*/
