/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:59:38 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 14:12:46 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data *init_data(char **envp)
{
	t_data *data;

	data = malloc(sizeof(data));
	if (!data)
		exit(EXIT_FAILURE);
	data->paths = get_paths(envp);
	if (!data->paths)
	{
		free(data);
		exit(EXIT_FAILURE);
	}
}

char	**get_paths(char **envp)
{
	char	**paths;
	size_t	i;

	paths = NULL;
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
			paths = ft_split(&envp[i][5], ":");
		i++;
	}
	return (paths);
}