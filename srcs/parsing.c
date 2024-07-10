/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:59:38 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 14:02:29 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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