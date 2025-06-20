/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakbour <kakbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:02:30 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/20 22:00:40 by kakbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "executor.h"
#include "minishell.h"

int	ft_is_builtin(t_token *token)
{
	if (!ft_strcmp(token->value, "echo"))
	{
		if (token->next)
		{
			if (!ft_echo(token->next))
				return (0);
		}	
		else
			write(1, "\n", 1);
		return (1);
	}
	if (!ft_strcmp(token->value, "env"))
		return (ft_env(token), 1);
	if (!ft_strcmp(token->value, "exit"))
		return (ft_exit(token), 1);
	if (!ft_strcmp(token->value, "pwd"))
		return (ft_pwd(token), 1);
	if (!ft_strcmp(token->value, "cd"))
		return (ft_cd(token), 1);
	if (!ft_strcmp(token->value, "export"))
		return (printf("this is export!\n"), 1);
	if (!ft_strcmp(token->value, "unset"))
		return (printf("this is unset!\n"), 1);
	return (0);
}

int		len_to_allocate(t_token *input)
{
	int i;

	i = 0;
	while(input)
	{
		if(input->type == CMD || input->type == ARG)
			i++;	
		input = input->next;
	}
	return (i);
}	

char	**ft_edit_exec_arr(t_token *input)
{
	t_token *tmp = input;
	int len = len_to_allocate(input);
	char **exec_arr = malloc((len + 1) * sizeof(char *));
	int i = 0;
	while (tmp)
	{
		if (tmp->type == CMD)
		{
			exec_arr[i++] = tmp->value;
			break;
		}
		tmp = tmp->next;
	}
	while (input)
	{
		if (input->type == ARG)
			exec_arr[i++] = input->value;
		else if (input->type == PIPE)
			break;
		input = input->next;
	}
	exec_arr[i] = NULL;
	return (exec_arr);
}

void	ft_execution_rest(t_token *input)
{
	char **exec_arr = ft_edit_exec_arr(input);
	int i = 0;
	while (exec_arr[i])
		printf("-->%s\n", exec_arr[i++]);
}

int	ft_excution(t_token *input)
{	
	ft_open_files(input);
	if (ft_is_builtin(input))
		return (1);
	else
		ft_execution_rest(input);
	return (0);
}
