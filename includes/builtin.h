/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:15:55 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/20 04:53:49 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

int		ft_echo(t_token *input);
int		ft_skip_echo_option(t_token **argument);

int		ft_env(t_token *temp);

int		ft_exit(t_token *argument);

int		ft_pwd(t_token *token);

void	ft_cd(t_token *list);

#endif