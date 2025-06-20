/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakbour <kakbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:02:30 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/20 18:11:04 by kakbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "executor.h"
#include "minishell.h"

int	ft_is_builtin(t_token *token)
{
	if (!ft_strcmp(token->value, "echo"))
	{
		if (token->next)
		{
			if (!ft_echo(token->next))
				return (0);
		}	
		else
			write(1, "\n", 1);
		return (1);
	}
	if (!ft_strcmp(token->value, "env"))
		return (ft_env(token), 1);
	if (!ft_strcmp(token->value, "exit"))
		return (ft_exit(token), 1);
	if (!ft_strcmp(token->value, "pwd"))
		return (ft_pwd(token), 1);
	if (!ft_strcmp(token->value, "cd"))
		return (ft_cd(token), 1);
	if (!ft_strcmp(token->value, "export"))
		return (printf("this is export!\n"), 1);
	if (!ft_strcmp(token->value, "unset"))
		return (printf("this is unset!\n"), 1);
	return (0);
}

int	ft_excution(t_token *input)
{	
	ft_open_files(input);
	if (ft_is_builtin(input))
		return (1);
	else
		;
	return (0);
}
