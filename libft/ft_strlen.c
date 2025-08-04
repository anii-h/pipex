/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:00:28 by anihamba          #+#    #+#             */
/*   Updated: 2025/02/13 19:29:53 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
/*
#include <string.h>
#include <stdio.h>

int main(void)
{
	char *s = "haylooo!";
	printf("%zu\n", strlen(s));
	printf("%zu", ft_strlen(s));
}*/
