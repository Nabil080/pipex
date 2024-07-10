/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:05:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 20:15:36 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_error(char *str, t_data *data)
{
	ft_putendl_fd("/!\\An error occured/!\\", 2);
	ft_putstr_fd("Error message : ", 2);
	ft_putendl_fd(str, 2);
	if (data)
		free_data(data);
	exit(EXIT_FAILURE);
}

void	free_data(t_data *data)
{
	size_t	i;

	if (!data)
		return ;
	if (data->paths)
		free_2d((void **)data->paths, 0);
	if (data->args)
	{
		i = 0;
		while (data->args[i])
		{
			free_2d((void **)data->args[i], 0);
			i++;
		}
		free(data->args);
	}
	free(data);
}