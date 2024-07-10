/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:12:51 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 21:47:35 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int ac, char **av)
{
	if (ac < 4)
		exit_error("arg count < 4", NULL);
	if (ft_strncmp(av[1], "here_doc", 8) && access(av[1], F_OK))
		exit_error("infile does not exist", NULL);
}
