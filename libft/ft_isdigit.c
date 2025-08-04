/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:33:21 by anihamba          #+#    #+#             */
/*   Updated: 2025/02/13 19:28:18 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
 


#include <ctype.h>
#include <stdio.h>

int main(void)
{
	int i = 48;
	printf("%d\n", isdigit(i));
	printf("%d", ft_isdigit(i));
}*/
