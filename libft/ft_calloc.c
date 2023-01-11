/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:57:58 by mfinette          #+#    #+#             */
/*   Updated: 2022/11/14 10:24:52 by mfinette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*space;

	if (nmemb && size > SIZE_MAX / nmemb)
		return (0);
	space = (void *)malloc(size * nmemb);
	if (!space)
		return (0);
	ft_bzero(space, size * nmemb);
	return (space);
}
