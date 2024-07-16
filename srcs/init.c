/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:12:51 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/16 19:49:40 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	get_here_doc(t_data *data, char *limiter)
{
	char	*line;

	data->in_fd = open("here_doc", O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (data->in_fd < 1)
		return ;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!ft_strncmp(line, limiter, ft_strlen(limiter)))
			return ;
		ft_putstr_fd(line, data->in_fd);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}

void	init_data(int ac, char **av, char **ev, t_data *data)
{
	data->paths = NULL;
	data->args = NULL;
	data->env = ev;
	data->is_heredoc = 0;
	if (!ft_strncmp(av[1], "here_doc", 8))
		data->is_heredoc = 1;
	data->count = ac - 3 - data->is_heredoc;
	if (data->is_heredoc)
		get_here_doc(data, av[2]);
	else
	{
		data->in_fd = open(av[1], O_RDONLY, 0777);
		if (data->in_fd < 1)
			exit_error("Can't open infile", NULL);
	}
	if (!data->is_heredoc)
		data->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		data->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (data->out_fd < 1)
	{
		close(data->in_fd);
		exit_error("Can't open outfile", NULL);
	}
}
