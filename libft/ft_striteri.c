/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:27:09 by mfinette          #+#    #+#             */
/*   Updated: 2022/11/10 20:00:17 by mfinette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t		size;
	size_t		i;

	size = 0;
	i = 0;
	if (s != 0)
	{
		size = ft_strlen(s);
		while (i < size)
		{
			(*f)(i, s);
			s++;
			i++;
		}
	}
}
