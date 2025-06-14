/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:02:30 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/14 21:43:15 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "executor.h"
#include "minishell.h"

int	ft_is_builtin(t_token *temp)
{
	if (!ft_strcmp(temp->value, "echo"))
	{
		if (temp->next)
		{
			if (!ft_echo(temp->next))
				return (0);
		}	
		else
			printf("\n");
		return (1);
	}
	if (!ft_strcmp(temp->value, "env"))
		return (ft_env(temp), 1);
	if (!ft_strcmp(temp->value, "exit"))
		return (ft_exit(temp), 1);
	if (!ft_strcmp(temp->value, "cd"))
		return (printf("this is cd!\n"), 1);
	if (!ft_strcmp(temp->value, "export"))
		return (printf("this is export!\n"), 1);
	if (!ft_strcmp(temp->value, "pwd"))
		return (printf("this is pwd!\n"), 1);
	if (!ft_strcmp(temp->value, "unset"))
		return (printf("this is unset!\n"), 1);
	return (0);
}

int	ft_excution(t_token *input)
{
	if (ft_is_builtin(input))
		return (1);
	else
		printf("to be done!\n");
	return (0);
}
