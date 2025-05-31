/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:43:18 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/30 17:43:59 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"

int	ft_env(t_token *temp)
{
	int	i;

	i = 0;
	while (temp->env[i])
		printf("%s\n", temp->env[i++]);
	return (1);
}
