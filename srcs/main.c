/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:22:38 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 18:17:09 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	// check que les args sont valides
	check_args(argc, argv);
	// valeurs de base de la struct
	data = init_data();
	if (!data)
		exit_error("An allocation failed", NULL);
	// recupere les path
	data->paths = get_paths(envp);
	if (!data->paths)
		exit_error("An allocation failed", data);
	// recupere les arguments
	data->args = get_args(argc, argv);
	if (!data->args)
		exit_error("An allocation failed", data);
	if (!check_exec(data))
		exit_error("A command is unknown", data);
	// boucle et execute chaque commande
	// clean et exit
	free_data(data);
	exit(EXIT_SUCCESS);
}