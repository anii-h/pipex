/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:54:26 by anihamba          #+#    #+#             */
/*   Updated: 2025/02/13 16:14:30 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	check;

	i = 0;
	check = 0;
	if (!needle[i])
		return ((char *) &haystack[i]);
	while (haystack[i] && len > i)
	{
		check = 0;
		if (haystack[i] == needle[check])
		{
			while (haystack[i + check] == needle[check]
				&& haystack[i + check] && len > (i + check))
				check++;
			if (!needle[check])
				return ((char *) &haystack[i]);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char b[42] = "chemistry is a very important subject";
	char *b1 = "nahhh, it's not!";

	printf("%s\n", strnstr(b1, b1, 11));
	printf("%s", ft_strnstr(b1, b1, 11));
}*/
