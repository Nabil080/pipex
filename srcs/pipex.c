/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:40:30 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/16 17:37:33 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec(t_data data, size_t	index)
{
	pid_t	pid;
	int		fd[2];

	//? pipe 
	//todo: check error
	pipe(fd);
	//? fork 
	//todo: check error
	pid = fork();
	//? parent attends la fin de l'enfant
	if (pid != 0)
	{
		wait(NULL);
		return ;
	}
	//? stdin devient fd_in (infile ou sortie ancienne pipe)
	dup2(data.in_fd, STDIN_FILENO);
	//? si derniere commande, stdout devient fd_out
	if (index == data.count - 1)
		dup2(data.out_fd, STDOUT_FILENO);
	//? sinon stdout devient l'entree de la nouvelle pipe
	else
		dup2(fd[1], STDOUT_FILENO);
	//? fd_in devient la sortie de la nouvelle pipe
	close(fd[1]);
	data.in_fd = fd[0];
	//? execute la commande
	execve(data.args[index][0], data.args[index], data.env);
}

void	maxi_piping(t_data data)
{
	size_t	cmd;

	if (data.is_heredoc)
		printf("heredoc\n");
	cmd = 0;
	while (data.args[cmd])
	{
		printf("\n-----Executing cmd[%zu]: %s-----\n", cmd, data.args[cmd][0]);
		printf("fd_in : %d, ft_out : %d\n", data.in_fd, data.out_fd);
		ft_exec(data, cmd);
		printf("\nDONE\n");
		cmd++;
	}
}