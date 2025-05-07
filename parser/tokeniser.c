/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:26:10 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/07 12:16:35 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "utils.h"

/*improved the logic of the function*/
/*joins nodes with no spaces in between and remove the nodes of spaces*/
/*keeps redirections >*/
int	is_operator(char *str)
{
	return (!ft_strcmp(str, "|") || !ft_strcmp(str, "<") || !ft_strcmp(str, ">")
		|| !ft_strcmp(str, "<<") || !ft_strcmp(str, ">>"));
}

void	ft_filtering_spaces(t_token *temp)
{
	t_token	*next;
	char	*joined;

	while (temp)
	{
		next = temp->next;
		if (next && ft_strcmp(next->value, " ") == 0)
		{
			ft_del_node(next);
			temp = temp->next;
			continue ;
		}
		if (next && !is_operator(temp->value) && !is_operator(next->value))
		{
			joined = ft_strjoin(temp->value, next->value);
			free(temp->value);
			temp->value = joined;
			ft_del_node(next);
			continue ;
		}
		temp = temp->next;
	}
}

/*change here*/
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
 * it must be preserved—do not remove it. */
int	ft_find_end(char *input, int *is_space, int *in_end)
{
	int		i;
	char	*delimiter;

	i = 0;
	delimiter = "\"\'";
	if (input[i] == '<' || input[i] == '>' || input[i] == '|')
	{
		if (input[i + 1] == '<' || input[i + 1] == '>')
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
