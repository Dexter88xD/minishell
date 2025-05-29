/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:18:53 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/30 00:45:03 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"
#include "utils.h"

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

// Added the if (i >= (int)ft_strlen(input)) condition
// because in the case of "echo \"test",
// there is a problem of accessing off limit character in input
// and valgrind prints invalid read of size of 1 because of how j incerements i
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
	while (input[i] != '\0')
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
		if (i >= (int)ft_strlen(input))
			break ;
	}
	return (edited_input);
}

int	ft_closed_quotes(t_token *input)
{
	int			i;
	t_quotes	count;

	i = 0;
	count.single_count = 0;
	count.double_count = 0;
	count.is_double_quote = 0;
	count.is_single_quote = 0;
	while (input->value[i])
	{
		if (input->value[i] == '\'' && !count.is_double_quote)
		{
			count.is_single_quote = !count.is_single_quote;
			count.single_count++;
		}
		else if (input->value[i] == '"' && !count.is_single_quote)
		{
			count.is_double_quote = !count.is_double_quote;
			count.double_count++;
		}
		i++;
	}
	if (count.double_count % 2 != 0 || count.single_count % 2 != 0)
		return (0);
	return (1);
}

t_token	*parsing(char *ret)
{
	t_token	*input;
	t_token	*temp;
	char	*buffer;

	input = NULL;
	temp = NULL;
	input = ft_edit_input(ret);
	ft_filtering_spaces(input);
	temp = input;
	while (temp)
	{
		if (!ft_closed_quotes(temp))
			return (printf("syntax error!\n"), ft_del_lst(input), NULL);
		buffer = ft_filter_quotes(temp);
		if (!buffer)
			return (NULL);
		free(temp->value);
		temp->value = buffer;
		temp = temp->next;
	}
	ft_setting_types(input);
	return (input);
}
