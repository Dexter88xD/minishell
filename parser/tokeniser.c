/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:26:10 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/14 21:47:27 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "utils.h"

void	ft_setting_types(t_token *input, char **env)
{
	int	i;

	i = 0;
	while (input)
	{
		input->env = env;
		if (ft_operator(input->value))
			input->type = OPERATOR;
		else if (!input->previous || (input->previous
				&& ft_strcmp(input->previous->value, "|") == 0))
			input->type = CMD;
		else
			input->type = ARG;
		input = input->next;
	}
}
/*improved the logic of the function*/
/*joins nodes with no spaces in between and remove the nodes of spaces*/
/*keeps redirections >*/

void	ft_is_end(char *delimiter, char *input, int *in_end, int *i)
{
	while (input[*i])
	{
		if (ft_strchr(delimiter, input[*i + 1]) || input[*i + 1] == ' '
			|| input[*i + 1] == '|' || input[*i + 1] == '<' || input[*i
				+ 1] == '>')
		{
			if (input[*i + 1] == ' ')
				*in_end = 1;
			break ;
		}
		(*i)++;
	}
}

/* The pipeline might look completely useless in the first condition,
 * but it's necessary to give it its own node.
 * For example, in a case like: "test"|successful
 * it must be preserved—do not remove it. 
 * Added the condition of input[i] != '|' in the case of: test |> test
 * the operators | and > were considered as one |> */
int	ft_find_end(char *input, int *is_space, int *in_end)
{
	int		i;
	char	*delimiter;

	i = 0;
	delimiter = "\"\'";
	if (input[i] == '<' || input[i] == '>' || input[i] == '|')
	{
		if (input[i] != '|' && (input[i + 1] == '<' || input[i + 1] == '>'))
			i++;
	}
	else if (ft_isspace(input[i]))
	{
		*is_space = 1;
		while (ft_isspace(input[i]))
			i++;
	}
	else if (ft_strchr((const char *)delimiter, input[i]))
	{
		i++;
		while (input[i] && input[i] != *input)
			i++;
	}
	else
		ft_is_end(delimiter, input, in_end, &i);
	return (i);
}
