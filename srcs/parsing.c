/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:59:38 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 20:30:10 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data *init_data(void)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit(EXIT_FAILURE);
	data->paths = NULL;
	data->args = NULL;
	return (data);
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

char	***get_args(int argc, char **argv)
{
	char	***args;
	int		i;

	args = malloc((argc - 2 + 1) * sizeof(char **));
	if (!args)
		return (NULL);
	i = 0;
	while (i + 2 < argc - 1)
	{
		args[i] = ft_split(argv[i + 2], " ");
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