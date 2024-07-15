/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:40:30 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/15 21:49:13 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	maxi_piping(t_data data)
{
	size_t	cmd;
	size_t	i;

	if (data.is_heredoc)
		printf("heredoc\n");
	cmd = 0;
	while (data.args[cmd])
	{
		printf("cmd[%zu] : %s |", cmd, data.args[cmd][0]);
		i = 1;
		while (data.args[cmd][i])
		{
			printf("arg[%zu] : %s ", i, data.args[cmd][i]);
			i++;
		}
		printf("\n");
		cmd++;
	}
}