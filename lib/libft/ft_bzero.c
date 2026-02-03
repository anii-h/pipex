/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:36:56 by anihamba          #+#    #+#             */
/*   Updated: 2025/02/13 19:30:37 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
#include <strings.h>
#include <stdio.h>

int	main(void)
{
	char s[] = "heyyyy!";
	char c[] = "heyyyy!";
	ft_bzero(s, 3);
	bzero(c, 1);
	printf("%s\n", s);
	printf("%s\n", c);
}*/
