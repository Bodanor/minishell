/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:38:39 by mfinette          #+#    #+#             */
/*   Updated: 2022/11/10 09:01:30 by mfinette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*charsource;
	char	*chardest;

	i = 0;
	charsource = (char *)src;
	chardest = (char *)dest;
	if (dest == src || n == 0)
		return (dest);
	while (i < n)
	{
		chardest[i] = charsource[i];
		i++;
	}
	return (dest);
}
