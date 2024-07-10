/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:59:38 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 21:45:40 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(int ac, char **av, t_data *data)
{
	data->paths = NULL;
	data->args = NULL;
	data->is_heredoc = 0;
	if (!ft_strncmp(av[1], "here_doc", 8))
		data->is_heredoc = 1;
	data->in_fd = 0;
	if (!data->is_heredoc)
	{
		data->in_fd = open(av[1], O_RDONLY, 0777);
		if (data->in_fd < 1)
			exit_error("Can't open infile", NULL);
	}
	if (!data->is_heredoc)
		data->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		data->out_fd = open("here_doc", O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (data->out_fd < 1)
	{
		close(data->in_fd);
		exit_error("Can't open outfile", NULL);
	}
}

char	**get_paths(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
			return (ft_split(&envp[i][5], ":"));
		i++;
	}
	return (NULL);
}

char	***get_args(int ac, char **av)
{
	char	***args;
	int		i;

	args = malloc((ac - 2 + 1) * sizeof(char **));
	if (!args)
		return (NULL);
	i = 0;
	while (i + 2 < ac - 1)
	{
		args[i] = ft_split(av[i + 2], " ");
		if (!args[i])
		{
			while (i--)
				free_2d((void **)args[i], 0);
			return (free(args), NULL);
		}
		i++;
	}
	args[i] = NULL;
	return (args);
}

static char	*get_exec(t_data *data, char **name)
{
	size_t	i;
	char	*exec_backslash;
	char	*exec;

	i = 0;
	while (data->paths[i])
	{
		exec_backslash = ft_strjoin(data->paths[i], "/");
		if (!exec_backslash)
			return (NULL);
		exec = ft_strjoin(exec_backslash, *name);
		free(exec_backslash);
		if (!exec)
			return (NULL);
		if (access(exec, X_OK) != -1)
		{
			free(*name);
			*name = exec;
			return (*name);
		}
		free(exec);
		i++;
	}
	return (NULL);
}

void	*check_exec(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->args[i])
	{
		if (access(data->args[i][0], X_OK) == -1)
			if (!get_exec(data, &data->args[i][0]))
				return (NULL);
		i++;
	}
	return (data);
}
