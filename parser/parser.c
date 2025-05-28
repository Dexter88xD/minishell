/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:18:53 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/28 22:14:22 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"
#include "utils.h"

void	ft_setting_types(t_token *input)
{
	while (input)
	{
		if (is_operator(input->value))
			input->type = OPERATOR;
		else if (!input->previous || (input->previous
				&& ft_strcmp(input->previous->value, "|") == 0))
			input->type = CMD;
		else
			input->type = ARG;
		input = input->next;
	}
}

void	ft_filtering_spaces(t_token *input)
{
	t_token	*next;
	char	*joined;

	while (input)
	{
		next = input->next;
		if (next && ft_strcmp(next->value, " ") == 0)
		{
			ft_del_node(next);
			input = input->next;
			continue ;
		}
		if (next && !is_operator(input->value) && !is_operator(next->value))
		{
			joined = ft_strjoin(input->value, next->value);
			free(input->value);
			input->value = joined;
			ft_del_node(next);
			continue ;
		}
		input = input->next;
	}
}

void	ft_edit_input_two(char *input, t_token **edited_input, int *i, int *j)
{
	char	*temp_str;
	t_token	*temp_node;

	temp_str = ft_strndup(input + (*i)++, (*j) + 1);
	if (temp_str)
	{
		temp_node = ft_new_node(temp_str, MALLOCED);
		if (temp_node)
			ft_add_node_back(edited_input, temp_node);
	}
}

t_token	*ft_edit_input(char *input)
{
	int		i;
	int		j;
	int		in_end;
	int		is_space;
	t_token	*edited_input;

	i = 0;
	j = 0;
	edited_input = NULL;
	while (input[i])
	{
		in_end = 0;
		is_space = 0;
		j = ft_find_end(input + i, &is_space, &in_end);
		if (is_space != 1)
			ft_edit_input_two(input, &edited_input, &i, &j);
		if ((is_space == 1 || in_end == 1) && i != 0)
			if (ft_last_node(edited_input)->value[0] != ' ')
				ft_add_node_back(&edited_input, ft_new_node(" ", 0));
		i += j;
	}
	return (edited_input);
}

t_token	*parsing(char *ret)
{
	t_token	*input;
	t_token	*temp;

	input = NULL;
	temp = NULL;
	input = ft_edit_input(ret);
	ft_filtering_spaces(input);
	ft_setting_types(input);
	return (input);
}
