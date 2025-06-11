/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:07:42 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/10 13:37:56 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"
#include "utils.h"

int	ft_size_until(char *input)
{
	int	i;

	i = 0;
	while (input[i] && ft_isalnum(input[i]))
		i++;
	return (i);
}

void	ft_set_sq(t_token *input)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	while (input)
	{
		i = 0;
		while (input->value[i])
		{
			if (input->value && input->quotes != -1 && input->value[i] == '\"')
				check = 1;
			if (input->value[i] == '\'' && check == 0)
			{
				input->quotes = -1;
				break ;
			}
			i++;
			if (input->value[i] == '\0')
				input->quotes = 0;
		}
		input = input->next;
	}
}

int	check_for_expand(t_token *input)
{
	if ((input->type == CMD || input->type == ARG) && input->quotes != -1)
		return (1);
	return (0);
}

void	find_path(t_token *input, int *i, int *d, int *check, int *save, int *j)
{
	while (input->env[*d])
	{
		*j = 0;
		while (input->value[*i + *j + 1] - input->env[*d][*j] == 0)
		{
			(*j)++;
			if (input->env[*d][*j] == '=' && ft_isalnum(input->value[*i + *j
					+ 1]) == 0)
			{
				*check = 1;
				break ;
			}
		}
		if (*check == 1)
			break ;
		(*d)++;
		if (*j != 0)
			*save = *j;
	}
}

void	ft_make_it(t_token *input, int *i, int check, int save, int j, int d)
{
	char	*a;
	char	*b;

	if (check == 1)
	{
		a = ft_strndup(input->value, *i);
		b = ft_strjoin(input->env[d] + j + 1, (input->value) + *i + j + 1);
		input->value = ft_strjoin(a, b);
		free(a), free(b);
		*i = *i + ft_strlen(input->env[d] + j) - 1;
	}
	else
	{
		a = ft_strndup(input->value, *i);
		b = input->value + *i + ft_size_until(input->value + *i + 1) + 1;
		input->value = ft_strjoin(a, b);
		free(a), free(b);
		*i = *i + save + ft_size_until(b + save + *i) - 1;
	}
}

void	ft_half_work(t_token *input, char **env)
{
	int	i;
	int	j;
	int	d;
	int	check;
	int	save;

	i = 0;
	j = 0;
	d = 0;
	check = 0;
	save = 0;
	input->env = env;
	while (input->value[i])
	{
		d = 0;
		check = 0;
		if (input->value[i] == '$')
		{
			find_path(input, &i, &d, &check, &save, &j);
			ft_make_it(input, &i, check, save, j, d);
		}
		else
			i++;
	}
}

void	ft_expand_var(t_token *input, char **env)
{
	ft_set_sq(input);
	while (input)
	{
		if (check_for_expand(input))
			ft_half_work(input, env);
		input = input->next;
	}
}
