/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:59:38 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 16:56:05 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data *init_data(void)
{
	t_data *data;

	data = malloc(sizeof(data));
	if (!data)
		exit(EXIT_FAILURE);
	data->paths = NULL;
	data->cmds = NULL;
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

static char	*get_command(char *name, char **paths)
{
	if (ft_strcontains(name, ' '))
		name = ft_substr(name, 0, ft_strcontains(name, ' '));
	else
		name = ft_strdup(name);
	if (!name)
		return (NULL);
	if (access(name, X_OK) != -1)
		return (name);
	return ("nope");
}

char	**get_commands(t_data *data, int argc, char **argv)
{
	char	**cmds;
	size_t	i;

	cmds = malloc((argc - 3 + 1) * sizeof(char *));
	i = 0;
	while (i + 2 < argc - 1)
	{
		cmds[i] = get_command(argv[i + 2], data->paths);
		i++;
	}
	cmds[i] = NULL;
	return (cmds);
}