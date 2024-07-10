/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:12:51 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 19:07:04 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int argc, char **argv)
{
	if (argc < 4)
		exit_error("arg count < 4", NULL);
	if (access(argv[1], F_OK))
		exit_error("infile does not exist", NULL);
}