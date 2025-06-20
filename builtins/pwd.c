/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:42:53 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/20 00:06:49 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"

int	ft_pwd(t_token *token)
{
	char	*pwd;
	int		i;

	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		printf("%s\n", pwd);
		free(pwd);
	}
	else
	{
		i = 0;
		while (token->env[i])
		{
			i++;
			if (!ft_strncmp(token->env[i], "PWD=", 4))
				break ;
		}
		printf("%s\n", token->env[i] + 4);
	}
	return (1);
}
