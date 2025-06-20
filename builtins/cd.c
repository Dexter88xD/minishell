/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:42:45 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/20 05:09:09 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"

void	ft_cd(t_token *list)
{
	int		i;
	char	*path;

	path = NULL;
	if (list->next)
	{
		path = list->next->value;
		if (chdir(path) == -1)
			perror("cd");
	}
	else
	{
		i = 0;
		while (list->env[i])
		{
			i++;
			if (!ft_strncmp(list->env[i], "HOME=", 5))
				break ;
		}
		path = list->env[i] + 5;
		if (chdir(path) == -1)
			perror("cd");
	}
}
