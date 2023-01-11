/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:37:17 by mfinette          #+#    #+#             */
/*   Updated: 2023/01/11 15:21:21 by mfinette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "libft/libft.h"

//////STRUCTURES//////

typedef struct s_command
{
	char	*command;
	char	*flags;
	char	**args;
}				t_command;

//////PARSING UTILS//////

int			len_until_space(char *str);
int			flag_number(char *str);
int			argument_number(char *str);

#endif