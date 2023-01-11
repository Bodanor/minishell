/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:13:00 by mfinette          #+#    #+#             */
/*   Updated: 2022/11/13 09:38:44 by mfinette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*buf;

	if (!s)
		return (0);
	i = 0;
	buf = ft_strdup(s);
	if (!buf)
		return (0);
	while (i < ft_strlen(s))
	{
		buf[i] = f(i, s[i]);
		i++;
	}
	return (buf);
}
