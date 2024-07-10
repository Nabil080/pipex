/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:22:59 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 20:34:06 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

/*structs*/
typedef struct s_data {
	char	**paths;
	char	***args;
}t_data;
/*check*/
void	check_args(int argc, char **argv);
/*parsing*/
t_data	*init_data(void);

char	**get_paths(char **envp);

char	***get_args(int argc, char **argv);

void	*check_exec(t_data *data);
/*exit*/
void	exit_error(char *str, t_data *data);

void	free_data(t_data *data);

#endif