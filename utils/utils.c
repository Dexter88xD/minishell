/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 00:43:06 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/07 15:42:15 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
	);
}
