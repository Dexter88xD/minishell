/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:02:30 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/28 23:05:46 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "executor.h"
#include "minishell.h"

int	is_it_builtin(t_token *temp)
{
	if (!ft_strcmp(temp->value, "echo"))
	{
		if (temp->next)
			ft_echo(temp->next);
		else
			printf("\n");
		return (1);
	}
	else if (!ft_strcmp(temp->value, "cd"))
		return (printf("this is cd!\n"), 1);
	else if (!ft_strcmp(temp->value, "env"))
		return (printf("this is env!\n"), 1);
	else if (!ft_strcmp(temp->value, "exit"))
		return (printf("this is exit!\n"), 1);
	else if (!ft_strcmp(temp->value, "export"))
		return (printf("this is export!\n"), 1);
	else if (!ft_strcmp(temp->value, "pwd"))
		return (printf("this is pwd!\n"), 1);
	else if (!ft_strcmp(temp->value, "unset"))
		return (printf("this is unset!\n"), 1);
	return (0);
}

int	excution(t_token *input)
{
	if (is_it_builtin(input))
		return (1);
	else
		printf("to be done!\n");
	return (0);
}
