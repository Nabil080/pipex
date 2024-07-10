/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:22:38 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 21:33:45 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	check_args(argc, argv);
	init_data(argc, argv, &data);
	data.paths = get_paths(envp);
	if (!data.paths)
		exit_error("An allocation failed", &data);
	data.args = get_args(argc, argv);
	if (!data.args)
		exit_error("An allocation failed", &data);
	if (!check_exec(&data))
		exit_error("A command is unknown", &data);
	// todo
	// maxi_piping(data);
	free_data(&data);
	exit(EXIT_SUCCESS);
}
