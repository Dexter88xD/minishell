/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakbour <kakbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:02:30 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/20 23:15:58 by kakbour          ###   ########.fr       */
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
	int len;

	len = 0;
	while(input)
	{
		if(input->type == CMD || input->type == ARG)
			len++;	
		input = input->next;
	}
	return (len);
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

void	cmd_not_found()
{
	write(2, "command not found\n", 18);
	exit(127);
}

char	**split_env(char **env)
{
	int		i;
	char	**path_splited;

	i = 0;
	while (env[i] && ft_strncmp("PATH=", env[i], 5) != 0)
		i++;
	if (env[i] == NULL)
		cmd_not_found();
	path_splited = ft_split(env[i] + 5, ':');
	return (path_splited);
}

int	check_absolute(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

int	check_cmd(char *PATH)
{
	if (access(PATH, F_OK) == 0)
		return (1);
	return (0);
}

char	*the_correct_path(char **path_splited, char **cmd)
{
	char	*tmp;
	char	*to_execute;
	int		i;

	i = 0;
	if (path_splited == NULL)
		return (NULL);
	if (check_absolute(cmd[0]))
		return (ft_strdup(cmd[0]));
	while (path_splited[i])
	{
		tmp = ft_strjoin(path_splited[i], "/");
		to_execute = ft_strjoin(tmp, cmd[0]);
		if (check_cmd(to_execute))
			break ;
		free(tmp);
		free(to_execute);
		i++;
	}
	if (path_splited[i] == NULL)
		cmd_not_found();
	return (free(tmp), to_execute);
}

void	ft_execution_rest(t_token *input)
{
	char **exec_arr = ft_edit_exec_arr(input);
	char **splited_path = split_env(input->env);
	char *to_execute = the_correct_path(splited_path, exec_arr);
	execve(to_execute, exec_arr, NULL);
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
