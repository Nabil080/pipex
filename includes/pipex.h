/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:22:59 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 15:57:04 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

/*structs*/
typedef struct s_data {
	char	**paths;
}t_data;

/*check*/
void	check_args(int argc, char **argv);

/*parsing*/
t_data *init_data(char **envp);

char	**get_paths(char **envp);
/*exit*/
void	exit_error(char *str);

#endif