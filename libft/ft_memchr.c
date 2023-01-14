/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:40:46 by mfinette          #+#    #+#             */
/*   Updated: 2022/11/10 16:32:26 by mfinette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	const unsigned char *s_cast = (const unsigned char*)s;
	
	i = 0;
	while (i < n)
	{
		if (s_cast[i] == (unsigned char)c)
			return (void*)&s_cast[i];
		i++;
	}
	return (0);
}
