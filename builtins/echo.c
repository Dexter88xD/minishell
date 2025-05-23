/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:42:37 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/23 15:40:52 by sohamdan         ###   ########.fr       */
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
	outcome = malloc(sizeof(argument->value));
	while (argument->value[i])
	{
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
		index++;
	}
	outcome[index] = '\0';
	return (outcome);	
}

int	ft_echo(t_token *argument)
{
	int	no_newline;

	no_newline = 0;
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
