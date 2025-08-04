/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:33:22 by anihamba          #+#    #+#             */
/*   Updated: 2025/02/20 14:02:30 by ani              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;

	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	return (ft_memset(temp, 0, size * count));
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{

}*/
