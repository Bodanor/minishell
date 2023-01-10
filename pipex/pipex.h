/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:08:16 by colas             #+#    #+#             */
/*   Updated: 2023/01/10 14:20:37 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "ft_err_printf/ft_printf.h"

typedef struct s_args
{
	char	**param;
}				t_args;

typedef struct s_pipex
{
	int		input;
	int		output;
	t_args	*cmd;
	char	**paths;

	int		fd_count;
}				t_pipex;

size_t	ft_strlen(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
void	free_all(char **strs);
char	*ft_strjoin(char const *s1, char const *s2);
char	*path_finder(char **envp);
void	error_code(char *str);
int		check_hub(t_pipex *pipex, char **argv, int argc);

#endif