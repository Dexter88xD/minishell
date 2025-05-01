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

int	ft_isspace(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

// char	which_meta(char c)
// {
// 	// if (c == '"')
// 	// 	return ('"');
// 	// if (c == '\'')
// 	// 	return ('\'');
// 	else
// 		return (c);
// }

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
