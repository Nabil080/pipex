/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:40:30 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/15 22:40:51 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec(t_data data, size_t	index)
{
	pid_t	pid;
	
	pid = fork();
	if (pid == 0)
	{
		dup2(data.in_fd, 0);
		if (index == data.count -1)
			dup2(data.out_fd, 1);
		execve(data.args[index][0], data.args[index], data.env);
	}
	else
	{
		wait(NULL);
		printf("Parent pid\n");
	}
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
		ft_exec(data, cmd);
		printf("\n-----DONE-----\n");
		cmd++;
	}
}