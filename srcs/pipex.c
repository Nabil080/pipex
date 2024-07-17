/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:40:30 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/17 22:26:20 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child(t_data data, size_t index, int fd[2])
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(data.out_fd);
	if (data.in_fd == -42)
		exit(EXIT_FAILURE);
	execve(data.args[index][0], data.args[index], data.env);
}

static void	ft_exec(t_data data, size_t	index)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit_error("A pipe failed", &data);
	pid = fork();
	if (pid == -1)	
	{
		close(fd[0]);
		close(fd[1]);
		exit_error("A fork failed", &data);
	}
	if (pid == 0)
		ft_child(data, index, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

void	maxi_piping(t_data data)
{
	size_t	index;
	pid_t	pid;

	index = 0;
	if (data.in_fd != -42)
	{
		dup2(data.in_fd, STDIN_FILENO);
		close(data.in_fd);
	}
	while (data.args[index + 1])
	{
		ft_exec(data, index);
		index++;
	}
	dup2(data.out_fd, STDOUT_FILENO);
	pid = fork();
	if (pid == -1)
		exit_error("A fork failed", &data);
	if (pid == 0)
	{
		close(data.out_fd);
		execve(data.args[index][0], data.args[index], data.env);
	}
	wait(NULL);
}
