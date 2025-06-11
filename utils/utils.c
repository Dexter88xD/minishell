/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 00:43:06 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/10 13:09:31 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

const char	*token_type_to_str(t_type type)
{
	static const char	*names[] = {"UNKNOWN", "CMD", "ARG", "OPERATOR"};

	return (names[type]);
}

int	check_if_integer(char *input)
{
	int	i;

	i = 0;
	if (input[0] == '-' || input[0] == '+')
		i++;
	while (input[i])
	{
		if (input[i] < '0' || input[i] > '9')
			return (0);
		i++;
	}
	if (!input[1])
		return (0);
	return (1);
}

int	ft_isspace(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	is_operator(char *str)
{
	return (
		!ft_strcmp(str, "|")
		|| !ft_strcmp(str, "<")
		|| !ft_strcmp(str, ">")
		|| !ft_strcmp(str, "<<")
		|| !ft_strcmp(str, ">>")
		|| !ft_strcmp(str, "<>")
		|| !ft_strcmp(str, "><")
	);
}
