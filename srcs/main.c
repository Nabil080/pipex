/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:22:38 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/15 22:31:57 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	test(t_data data)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(data.args[0][0], &data.args[0][0], data.env);
	wait(NULL);
	printf("Parent\n");
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	check_args(ac, av);
	init_data(ac, av, env, &data);
	data.paths = get_paths(env);
	if (!data.paths)
		exit_error("An allocation failed", &data);
	data.args = get_args(data, av);
	if (!data.args)
		exit_error("An allocation failed", &data);
	if (!check_exec(&data))
		exit_error("A command is unknown", &data);
	if (0)
		test(data);
	// todo : piping
	maxi_piping(data);
	free_data(&data);
	exit(EXIT_SUCCESS);
}
