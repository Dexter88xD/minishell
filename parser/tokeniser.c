/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:26:10 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/01 14:50:21 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "utils.h"

int	ft_is_end(char *delimiter, char *input, int *in_end, int *i)
{
	if (ft_strchr(delimiter, input[*i + 1]) || input[*i] == ' ')
	{
		if (input[*i] == ' ')
			*in_end = 1;
		return (1);
	}
	(*i)++;
	return (0);
}

int	ft_isspace(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

char	which_meta(char c)
{
	if (c == '"')
		return ('"');
	if (c == '\'')
		return ('\'');
	else
		return (c);
}

int	ft_find_end(char *input, int *is_space, int *in_end)
{
	int		i;
	char	meta_end;
	char	*delimiter;

	i = 0;
	delimiter = "\"\'";
	meta_end = which_meta(input[i]);
	if (ft_isspace(input[i]))
	{
		*is_space = 1;
		while (ft_isspace(input[i]))
			i++;
	}
	else if (ft_strchr((const char *)delimiter, input[i]))
	{
		i++;
		while (input[i] && input[i] != meta_end)
			i++;
	}
	else
	{
		i++;
		while (input[i])
			if (ft_is_end(delimiter, input, in_end, &i))
				break ;
	}
	return (i);
}
