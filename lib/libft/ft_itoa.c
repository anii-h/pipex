/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:08:52 by anihamba          #+#    #+#             */
/*   Updated: 2025/02/20 14:45:47 by ani              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_of_digits(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n *= -1;
	if (n == 0)
		return (1);
	while (!(n / 10 == 0 && n % 10 == 0))
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*convert(char *res, int i, int n, int sign)
{
	if (n == 0)
		res[0] = 48;
	while (n != 0)
	{
		res[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*res;

	i = number_of_digits(n);
	sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n >= 0)
		res = (char *)malloc(i + 1);
	else
	{
		sign = -1;
		n *= -1;
		i++;
		res = (char *)malloc(i + 1);
	}
	if (!res)
		return (NULL);
	res[i--] = 0;
	return (convert(res, i, n, sign));
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(0));
}*/
