/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:40:30 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/16 19:51:54 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec(t_data data, size_t	index)
{
	pid_t	pid;
	int		fd[2];

	printf("\n-----Executing cmd[%zu]: %s-----\n", index, data.args[index][0]);
	//todo: check error
	pipe(fd);
	//todo: check error
	pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execve(data.args[index][0], data.args[index], data.env);
	}
}

void	maxi_piping(t_data data)
{
	size_t	cmd;

	cmd = 0;
	dup2(data.in_fd, STDIN_FILENO);
	while (data.args[cmd + 1])
	{
		ft_exec(data, cmd);
		cmd++;
	}
	dup2(data.out_fd, STDOUT_FILENO);
	execve(data.args[cmd][0], data.args[cmd], data.env);
}