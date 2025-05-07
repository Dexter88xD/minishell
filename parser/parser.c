/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:18:53 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/06 22:55:28 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "utils.h"

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
			ft_add_node_back(&edited_input,
				ft_new_node(ft_strndup(input + i++, j + 1)));
		if ((is_space == 1 || in_end == 1) && i != 0)
			if (ft_last_node(edited_input)->value[0] != ' ')
				ft_add_node_back(&edited_input, ft_new_node(" "));
		i += j;
	}
	return (edited_input);
}
