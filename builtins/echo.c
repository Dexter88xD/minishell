/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:42:37 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/20 16:48:37 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "minishell.h"

char	*ft_filter_quotes(t_token *argument)
{
	int		i;
	int		index;
	char	*outcome;

	i = 0;
	index = 0;
	while (argument->value[i])
	{
		outcome = malloc(sizeof(argument->value));
		if (argument->value[i] == '"')
		{
			i++;
			while (argument->value && argument->value[i] != '"')
			{
				outcome[index] = argument->value[i];
				i++;
			}
			if (argument->value && argument->next && argument->value[i] == '"')
			i++;
		}
		else
			outcome[index] = argument->value[i];
		i++;
		printf("%s", outcome);
		// free(outcome);
	}
	return (outcome);	
}

int	ft_echo(t_token *argument)
{
	int	no_newline;

	while (argument && argument->type != OPERATOR)
	{
		if (argument->value[0] == '-')
		{
			if (!ft_strcmp(argument->value, "-n"))
			{
				no_newline = 1;
				argument = argument->next;
				if (!argument)
				break ;
			}
		}
		argument->value = ft_filter_quotes(argument);
		if (!argument->value)
			printf("khawarti\n");
		else
			printf("%s", argument->value);
		if (argument->next)
			printf(" ");
		argument = argument->next;
	}
	if (no_newline == 0)
		printf("\n");
	return (0);
}
