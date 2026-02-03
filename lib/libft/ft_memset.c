/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:47:50 by anihamba          #+#    #+#             */
/*   Updated: 2025/02/13 19:30:16 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *) b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}
/*
#include <string.h>
#include <stdio.h>

int main(void)
{
	char s[] = "HAYLOOO ";
	char c[] = "HAYLOOO ";
	printf("%s\n", memset(s, -5, 2));
	printf("%s", ft_memset(c, -5, 2));
}*/
