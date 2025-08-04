/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:22:32 by anihamba          #+#    #+#             */
/*   Updated: 2025/02/13 19:31:13 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	k;
	char	*res;
	char	*tocpy;

	k = 0;
	res = dst;
	tocpy = (char *)src;
	if (res == NULL && tocpy == NULL)
		return (dst);
	while (k < n)
	{
		res[k] = tocpy[k];
		k++;
	}
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>

int main(void)
{
	char s[] = "heyooo";
	char c[] = "kkkkkk";
	char k[] = "heyooo";
	printf("%s\n", ft_memcpy(s, c, 3));
	printf("%s\n", memcpy(k, c, 3));
}*/
