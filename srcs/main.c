/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:22:38 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 16:56:15 by nbellila         ###   ########.fr       */
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
	// recupere les path
	data->paths = get_paths(envp);
	// ft_putarr(data->paths);
	// recupere les commandes
	data->cmds = get_commands(data, argc, argv);
	ft_putarr(data->cmds);
	// recupere les arguments
	// boucle et execute chaque commande
	// clean et exit
}