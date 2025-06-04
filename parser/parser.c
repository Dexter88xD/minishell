/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:18:53 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/30 00:45:03 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"
#include "utils.h"

void	ft_edit_input_two(char *input, t_token **edited_input, int *i, int *j)
{
	char	*temp_str;
	t_token	*temp_node;

	temp_str = ft_strndup(input + (*i)++, (*j) + 1);
	if (temp_str)
	{
		temp_node = ft_new_node(temp_str, MALLOCED);
		if (temp_node)
			ft_add_node_back(edited_input, temp_node);
	}
}

// Added the if (i >= (int)ft_strlen(input)) condition
// because in the case of "echo \"test",
// there is a problem of accessing off limit character in input
// and valgrind prints invalid read of size of 1 because of how j incerements i
t_token	*ft_edit_input(char *input)
{
	int		i;
	int		j;
	int		in_end;
	int		is_space;
	t_token	*edited_input;

	i = 0;
	j = 0;
	edited_input = NULL;
	while (input[i] != '\0')
	{
		in_end = 0;
		is_space = 0;
		j = ft_find_end(input + i, &is_space, &in_end);
		if (is_space != 1)
			ft_edit_input_two(input, &edited_input, &i, &j);
		if ((is_space == 1 || in_end == 1) && i != 0)
			if (ft_last_node(edited_input)->value[0] != ' ')
				ft_add_node_back(&edited_input, ft_new_node(" ", 0));
		i += j;
		if (i >= (int)ft_strlen(input))
			break ;
	}
	return (edited_input);
}

int	ft_closed_quotes(t_token *input)
{
	int			i;
	t_quotes	count;

	i = 0;
	count.single_count = 0;
	count.double_count = 0;
	count.is_double_quote = 0;
	count.is_single_quote = 0;
	while (input->value[i])
	{
		if (input->value[i] == '\'' && !count.is_double_quote)
		{
			count.is_single_quote = !count.is_single_quote;
			count.single_count++;
		}
		else if (input->value[i] == '"' && !count.is_single_quote)
		{
			count.is_double_quote = !count.is_double_quote;
			count.double_count++;
		}
		i++;
	}
	if (count.double_count % 2 != 0 || count.single_count % 2 != 0)
		return (0);
	return (1);
}
int is_equale(char a, char b)
{
	return(a - b);
}

int ft_size_until(char *input)
{
	int i;

	i = 0;
	while(input[i] && ft_isalnum(input[i]))
		i++;
	return (i);
}

void ft_set_sq(t_token *input)
{
	int	i;
	int check = 0;

	i = 0;
	while(input)
	{
		i = 0;
		while(input->value[i])
		{
			if(input->quotes != -1 && input->value[i] == '\"')
				check = 1;
			if(input->value[i] == '\'' && check == 0)
			{
				input->quotes = -1;
				break;
			}
			i++;
		}
		input = input->next;
	}
}

void	ft_expand_var(t_token *input)
{
	int i = 0;
	int j = 0;
	int d = 0;
	int check = 0;
	int save = 0;
	char *sec;
	char *buffer;
	ft_set_sq(input);
	char **env = input->env;
	while(input)
	{
		i = 0;
		if((input->type == CMD || input->type == ARG) && input->quotes != -1)
		{
			while(input->value[i])
			{
				d = 0;
				check = 0;
				if(input->value[i] == '$')
				{
					while(env[d])
					{
						j = 0;
						while(is_equale(input->value[i + j + 1], env[d][j]) == 0)
						{
							j++;
							if(env[d][j] == '=' && ft_isalnum(input->value[i + j + 1]) == 0)
							{
								check = 1;
								break;
							}
						}
						if(check == 1)
							break;
						d++;
						if(j != 0)
						{
							save = j;
						}
					}
					if(check == 1)
					{
						sec = ft_strndup(input->value, i);
						buffer = ft_strjoin(env[d] + j + 1, (input->value) + i + j + 1);
						sec = ft_strjoin(sec , buffer);
						input->value = sec;
						i = i + ft_strlen(env[d] + j) - 1;
					}
					else
					{
						char *a = ft_strndup(input->value ,i);
						char *b = input->value + i + ft_size_until(input->value + i + 1) + 1;
						input->value = ft_strjoin(a , b);
						i = i + save + ft_size_until(buffer + save + i) - 1;
					}
				}
				else
					i++;
			}
		}
		input = input->next;
	}
}
t_token	*parsing(char *ret, char **env)
{
	t_token	*input;
	t_token	*temp;
	char	*buffer;

	input = NULL;
	temp = NULL;
	input = ft_edit_input(ret);
	input->env = env;
	ft_filtering_spaces(input);
	ft_setting_types(input);
	ft_expand_var(input);
	temp = input;
	while (temp)
	{
		if (!ft_closed_quotes(temp))
			return (printf("syntax error!\n"), ft_del_lst(input), NULL);
		buffer = ft_filter_quotes(temp);
		if (!buffer)
			return (NULL);
		free(temp->value);
		temp->value = buffer;
		temp = temp->next;
	}
	return (input);
}
