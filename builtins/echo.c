/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:42:37 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/30 00:35:09 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parser.h"
#include "minishell.h"

int	ft_echo(t_token *argument)
{
	int		no_newline;

	no_newline = 0;
	if (!ft_strcmp(argument->value, "-n"))
	{
		no_newline = 1;
		argument = argument->next;
	}
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
