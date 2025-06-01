/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:43:44 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/01 17:18:18 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "minishell.h"
#include "utils.h"

int	ft_exit(t_token *argument)
{
	unsigned int	num;
	t_token			*temp;

	printf("exit\n");
	if (ft_size_lst(argument) > 2)
		return (printf("bash: exit: too many arguments\n"), 1);
	num = 0;
	temp = argument->next;
	if (temp)
	{
		if (!check_if_integer(temp->value))
		{
			printf("bash: exit: %s: numeric argument required\n", temp->value);
			ft_del_lst(argument);
			exit(2);
		}
		num = ft_atoi(temp->value);
		ft_del_lst(argument);
		exit(num);
	}
	ft_del_lst(argument);
	return (exit(num), 1);
}
