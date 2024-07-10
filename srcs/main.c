/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:22:38 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 21:50:21 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;

	check_args(ac, av);
	init_data(ac, av, &data);
	data.paths = get_paths(env);
	if (!data.paths)
		exit_error("An allocation failed", &data);
	data.args = get_args(data, ac, av);
	if (!data.args)
		exit_error("An allocation failed", &data);
	if (!check_exec(&data))
		exit_error("A command is unknown", &data);
	// todo
	// maxi_piping(data);
	free_data(&data);
	exit(EXIT_SUCCESS);
}
