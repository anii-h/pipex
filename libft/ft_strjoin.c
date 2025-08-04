/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:00:18 by anihamba          #+#    #+#             */
/*   Updated: 2025/02/15 17:11:36 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	len;
	char	*res;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = 0;
	res = (char *)malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	while (len < len1)
	{
		res[len] = s1[len];
		len++;
	}
	while (len - len1 < len2)
	{
		res[len] = s2[len - len1];
		len++;
	}
	res[len] = 0;
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strjoin("aua", "aua"));
}*/
