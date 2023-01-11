/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:51:54 by mfinette          #+#    #+#             */
/*   Updated: 2023/01/11 16:30:11 by mfinette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// DECOMPOSITION = "command" + "-flag" + "arguments"

char	*get_command(char *line)
{
	int		i;
	char	*command;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && line[i] == ' ')
		i++;
	command = malloc(sizeof(char));
	command = ft_strnjoin(command, &line[i], len_until_space(&line[i]));
	return (command);
}

char	*get_flags(char *line)
{
	int		i;
	int		count;
	char	*flag;

	i = 0;
	count = 0;
	if (!line)
		return (0);
	flag = malloc(sizeof(char));
	while (line[i] && line[i] != '-')
		i++;
	while (count < flag_number(line))
	{
		i++;
		flag = ft_strnjoin(flag, &line[i], len_until_space(&line[i]));
		while (line[i] && line[i] != '-')
			i++;
		count++;
	}
	return (flag);
}

char	*get_arguments(char *line)
{
	int	i;
	int	count;

	if (!line)
		return (0);
	count = 0;
	i = 0;
	while (line[i] && count < flag_number(line))
	{
		if (line[i] == '-')
			count++;
		i++;
	}
	while (line[i] && line[i] != ' ')
		i++;
	i++;
	return (&line[i]);
}

t_command	parse_command(char *line)
{
	t_command	command;

	command.command = get_command(line);
	command.flags = get_flags(line);
	command.args = ft_split(get_arguments(line), ' ');
	return (command);
}

// int	main(int argc, char **argv)
// {
// 	t_command	command;
// 	int			i;

// 	(void)argc;
// 	i = 0;
// 	command = parse_command(argv[1]);
// 	printf("command = %s\n", command.command);
// 	printf("flags = %s\n", command.flags);
// 	while (command.args[i])
// 	{
// 		printf("argument %d = %s\n", i + 1, command.args[i]);
// 		// free(command.args[i]);
// 		i++;
// 	}
// 	// free(command.command);
// 	// free(command.flags);
// 	// free(command.args);
// }
