/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:10:38 by mfinette          #+#    #+#             */
/*   Updated: 2022/11/12 08:33:36 by mfinette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((!str || !to_find) && len == 0)
		return (0);
	if (to_find[0] == 0)
		return ((char *)str);
	while (str[i] && i < len)
	{
		while (to_find[j] && i + j < len)
		{
			if (str[i + j] != to_find[j])
				break ;
			j++;
			if (!to_find[j])
				return (&((char *)str)[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}
