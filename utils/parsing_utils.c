/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:56:25 by mfinette          #+#    #+#             */
/*   Updated: 2023/01/11 14:57:03 by mfinette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	len_until_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

int	flag_number(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '-' && str[i - 1] == ' ')
			return (count);
		if (str[i] == '-')
			count++;
		i++;
	}
	return (count);
}

int	argument_number(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '-' && str[i - 1] == ' ')
			count++;
		i++;
	}
	return (count);
}
