/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:05:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 16:00:01 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_error(char *str)
{
	ft_putendl_fd("/!\\An error occured/!\\", 2);
	ft_putstr_fd("Error message : ", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}