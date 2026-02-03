/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:07:06 by anihamba          #+#    #+#             */
/*   Updated: 2025/02/13 19:32:07 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(src);
	if (len < dstsize)
		ft_memcpy(dst, src, len + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (len);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char dst[] = "1";
	char src[] = "aaaaaaaaaaa";
	printf("%lu\n%s\n", strlcpy(dst, src, 2), dst);
	printf("%lu\n%s", ft_strlcpy(dst, src, 2), dst);
}*/
