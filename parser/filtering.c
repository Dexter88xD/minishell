/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:35:30 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/14 23:30:22 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "builtin.h"
#include "utils.h"

void	ft_filtering_spaces(t_token *input)
{
	t_token	*next;
	char	*joined;

	while (input)
	{
		next = input->next;
		if (next && ft_strcmp(next->value, " ") == 0)
		{
			ft_del_node(&next);
			input = input->next;
			continue ;
		}
		if (next && !ft_operator(input->value) && !ft_operator(next->value))
		{
			joined = ft_strjoin(input->value, next->value);
			free(input->value);
			input->value = joined;
			ft_del_node(&next);
			continue ;
		}
		input = input->next;
	}
}

void	ft_double_quotes(t_token *argument, char *outcome, int *i, int *index)
{
	argument->quotes = DOUBLE_QUOTES;
	(*i)++;
	while (argument->value && argument->value[(*i)] != '"')
	{
		outcome[(*index)] = argument->value[(*i)];
		(*index)++;
		(*i)++;
	}
	if (argument->value[(*i)] == '"')
		(*i)++;
}

void	ft_single_quotes(t_token *argument, char *outcome, int *i, int *index)
{
	argument->quotes = SINGLE_QUOTES;
	(*i)++;
	while (argument->value && argument->value[(*i)] != '\'')
	{
		outcome[(*index)] = argument->value[(*i)];
		(*index)++;
		(*i)++;
	}
	if (argument->value[(*i)] == '\'')
		(*i)++;
}

char	*ft_filter_quotes(t_token *argument)
{
	int		i;
	int		index;
	char	*outcome;

	i = 0;
	index = 0;
	outcome = malloc(ft_strlen(argument->value) * sizeof(argument->value) + 1);
	if (!outcome)
		return (NULL);
	while (argument->value[i])
	{
		if (argument->value[i] == '"')
			ft_double_quotes(argument, outcome, &i, &index);
		else if (argument->value[i] == '\'')
			ft_single_quotes(argument, outcome, &i, &index);
		else
		{
			outcome[index] = argument->value[i];
			index++;
			i++;
		}
	}
	outcome[index] = '\0';
	return (outcome);
}
