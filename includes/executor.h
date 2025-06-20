/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakbour <kakbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:16:19 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/20 16:49:50 by kakbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

int	ft_is_builtin(t_token *temp);
int	ft_excution(t_token *input);
void	ft_open_files(t_token *input);

#endif