/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:42:37 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/10 17:09:24 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include "parser.h"

int	ft_skip_echo_option(t_token **argument)
{
	int	no_newline;
	int	i;

	no_newline = 0;
	i = 0;
	if ((*argument)->value[i] == '-')
	{
		i++;
		while ((*argument)->value[i] && (*argument)->value[i] == 'n')
			i++;
		if (!(*argument)->value[i] && ((*argument)->value[i - 1]
				&& (*argument)->value[i - 1] == 'n'))
		{
			no_newline = 1;
			(*argument) = (*argument)->next;
		}
	}
	return (no_newline);
}

int	ft_echo(t_token *argument)
{
	int	no_newline;

	no_newline = ft_skip_echo_option(&argument);
	while (argument && argument->type != OPERATOR)
	{
		printf("%s", argument->value);
		if (argument->next)
			printf(" ");
		argument = argument->next;
	}
	if (no_newline == 0)
		printf("\n");
	return (1);
}
