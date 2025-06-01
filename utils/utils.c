/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 00:43:06 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/01 17:15:34 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
