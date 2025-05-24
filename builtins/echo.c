/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:42:37 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/24 15:42:09 by sohamdan         ###   ########.fr       */
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
	if (!outcome)
		return (NULL);
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
	char	*temp;

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
		temp = ft_filter_quotes(argument);
		if (!temp)
			return (-1);
		free(argument->value);
		argument->value = temp;
		printf("%s", argument->value);
		if (argument->next)
			printf(" ");
		argument = argument->next;
	}
	if (no_newline == 0)
		printf("\n");
	return (0);
}
