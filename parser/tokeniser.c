/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:26:10 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/06 11:48:06 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "utils.h"

/*joins nodes with no spaces in between and remove the nodes of spaces*/
void	ft_filtering_spaces(t_token *temp)
{
	while (temp)
	{
		if (!ft_strcmp(temp->value, " "))
		{
			ft_del_node(temp);
			temp = temp->next;
			continue ;
		}
		while (temp && temp->next && ft_strcmp(temp->value, " ")
			&& ft_strcmp(temp->next->value, " "))
		{
			temp->value = ft_strjoin(temp->value, temp->next->value);
			ft_del_node(temp->next);
		}
		temp = temp->next;
	}
}

/*change here*/
void	ft_is_end(char *delimiter, char *input, int *in_end, int *i)
{
	while (input[*i])
	{
		if (ft_strchr(delimiter, input[*i + 1]) || input[*i + 1] == ' ')
		{
			if (input[*i + 1] == ' ')
				*in_end = 1;
			break ;
		}
		(*i)++;
	}
}

/*small changes in this function*/
int	ft_find_end(char *input, int *is_space, int *in_end)
{
	int		i;
	char	*delimiter;

	i = 0;
	delimiter = "\"\'";
	if (ft_isspace(input[i]))
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
	{
		i++;
		ft_is_end(delimiter, input, in_end, &i);
	}
	return (i);
}
