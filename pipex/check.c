/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:37:28 by colas             #+#    #+#             */
/*   Updated: 2023/01/10 15:36:05 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_err_printf/ft_printf.h"

int	check_param(t_pipex *ppx, char *param)
{
	char	*pathing;
	char	*slashed;
	int		i;

	if (param == NULL)
		return (ft_err_printf("msh: permission denied:\n"), 2);
	i = 0;
	while (ppx->paths[i])
	{
		slashed = ft_strjoin(ppx->paths[i], "/");
		pathing = ft_strjoin(slashed, param);
		free(slashed);
		if (access(pathing, F_OK) == 0)
			return (free(pathing), 0);
		free(pathing);
		i++;ß
	}
	return (1);
}

void	get_check_cmds_between(t_pipex *ppx, char **argv, int argc)
{
	int	i;

	i = 3;
	while (i < (argc - 2))
	{
		ppx->cmd[i].param = ft_split(argv[i], ' ');
		if (!ppx->cmd[i].param)
			return (free_all(ppx->cmd->param));
		if (check_param(ppx, ppx->cmd[i].param[0]) == 1)
			ft_err_printf("msh: command not found: %s\n", ppx->cmd[i].param[0]);
		i++;
	}
}

void	check_input(t_pipex *ppx, char **argv)
{
	ppx->input = open(argv[1], O_RDONLY);
	if (ppx->input == -1)
	{
		if (access(argv[1], F_OK) == 0)
			ft_err_printf("msh: permission denied: %s\n", argv[1]);
		else
			ft_err_printf("msh: no such file or directory: %s\n", argv[1]);
		return ;
	}
	ppx->cmd[0].param = ft_split(argv[2], ' ');
	if (!ppx->cmd[0].param)
		return ;
	if (check_param(ppx, ppx->cmd[0].param[0]) == 1)
		ft_err_printf("msh: command not found: %s\n", ppx->cmd->param[0]);
}

void	check_output(t_pipex *ppx, char **argv, int argc)
{
	ppx->output = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (ppx->output == -1)
	{
		ft_err_printf("msh: permission denied: %s\n", argv[argc - 1]);
		return ;
	}
	ppx->cmd[argc - 1].param = ft_split(argv[argc - 1], ' ');
	if (!ppx->cmd[argc - 1].param)
		return (free_all(ppx->cmd->param));
}

int	check_hub(t_pipex *ppx, char **argv, int argc)
{
	ppx->cmd = malloc(sizeof(t_args) * 2);
	if (!ppx->cmd)
		return (0);
	check_input(ppx, argv);
	get_check_cmds_between(ppx, argv, argc);
	check_output(ppx, argv, argc);
	return (1);
}
