/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 03:10:14 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/19 13:22:30 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"

void	ft_find_env_match(t_token *token, t_index *index)
{
	while (token->env[index->env])
	{
		index->match = 0;
		while (token->value[index->val + index->match + 1]
			- token->env[index->env][index->match] == 0)
		{
			index->match++;
			if (token->env[index->env][index->match] == '='
				&& !ft_isalnum(token->value[index->val + index->match + 1]))
			{
				index->found_match = 1;
				break ;
			}
			if (index->val + index->match + 1 > (int)ft_strlen(token->value))
				break ;
		}
		if (index->found_match == 1)
			break ;
		index->env++;
		if (index->match != 0)
			index->last_match_len = index->match;
	}
}

int	ft_var_name_length(char *token)
{
	int	index;

	index = 0;
	while (token[index] && ft_isalnum(token[index]))
		index++;
	return (index);
}

void	ft_detect_quote_type(t_token *token)
{
	int	i;
	int	double_quote_found;

	double_quote_found = 0;
	while (token)
	{
		i = 0;
		while (token->value[i])
		{
			if (token->value && token->quotes != -1 && token->value[i] == '\"')
				double_quote_found = 1;
			if (token->value[i] == '\'' && double_quote_found == 0)
			{
				token->quotes = -1;
				break ;
			}
			i++;
			if (token->value[i] == '\0')
				token->quotes = 0;
		}
		token = token->next;
	}
}

int	ft_should_expand(t_token *token)
{
	if ((token->type == CMD || token->type == ARG) && token->quotes != -1)
		return (1);
	return (0);
}
