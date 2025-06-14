/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:07:42 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/14 22:23:40 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"
#include "utils.h"

int	ft_var_name_length(char *token)
{
	int	index;

	index = 0;
	while (token[index] && ft_isalnum(token[index]))
		index++;
	return (index);
}

void	ft_detect_quote_type(t_token *token)
{
	int	i;
	int	double_quote_found;

	double_quote_found = 0;
	while (token)
	{
		i = 0;
		while (token->value[i])
		{
			if (token->value && token->quotes != -1 && token->value[i] == '\"')
				double_quote_found = 1;
			if (token->value[i] == '\'' && double_quote_found == 0)
			{
				token->quotes = -1;
				break ;
			}
			i++;
			if (token->value[i] == '\0')
				token->quotes = 0;
		}
		token = token->next;
	}
}

int	ft_should_expand(t_token *token)
{
	if ((token->type == CMD || token->type == ARG) && token->quotes != -1)
		return (1);
	return (0);
}

void	ft_find_env_match(t_token *token, int *val_index, int *env_index,
		int *found_match, int *last_valid_match_len, int *match_index)
{
	while (token->env[*env_index])
	{
		*match_index = 0;
		while (token->value[*val_index + *match_index + 1] - token->env[*env_index][*match_index] == 0)
		{
			(*match_index)++;
			if (token->env[*env_index][*match_index] == '=' && ft_isalnum(token->value[*val_index + *match_index + 1]) == 0)
			{
				*found_match = 1;
				break ;
			}
		}
		if (*found_match == 1)
			break ;
		(*env_index)++;
		if (*match_index != 0)
			*last_valid_match_len = *match_index;
	}
}

void	ft_expand_token_value(t_token *token, int *val_index, int found_match,
		int last_valid_match_len, int match_index, int env_index)
{
	char	*prefix;
	char	*suffix;

	if (found_match == 1)
	{
		prefix = ft_strndup(token->value, *val_index);
		suffix = ft_strjoin(token->env[env_index] + match_index + 1, (token->value) + *val_index + match_index + 1);
		token->value = ft_strjoin(prefix, suffix);
		if (prefix)
			free(prefix);
		if (suffix)
			free(suffix);
		*val_index = *val_index + ft_strlen(token->env[env_index] + match_index) - 1;
	}
	else
	{
		prefix = ft_strndup(token->value, *val_index);
		suffix = token->value + *val_index + ft_var_name_length(token->value + *val_index + 1) + 1;
		token->value = ft_strjoin(prefix, suffix);
		if (prefix)
			free(prefix);
		*val_index = *val_index + last_valid_match_len + ft_var_name_length(suffix + last_valid_match_len + *val_index) - 1;
	}
}

void	ft_expand_token_string(t_token *token)
{
	int	val_index;
	int	match_index;
	int	env_index;
	int	found_match;
	int	last_valid_match_len;

	val_index = 0;
	match_index = 0;
	last_valid_match_len = 0;
	while (token->value[val_index])
	{
		env_index = 0;
		found_match = 0;
		if (token->value[val_index] == '$')
		{
			ft_find_env_match(token, &val_index, &env_index, &found_match, &last_valid_match_len, &match_index);
			ft_expand_token_value(token, &val_index, found_match, last_valid_match_len, match_index, env_index);
		}
		else
			val_index++;
		if (val_index < 0)
			val_index = 0;
	}
}

void	ft_expand_all_tokens(t_token *token_list)
{
	ft_detect_quote_type(token_list);
	while (token_list)
	{
		if (ft_should_expand(token_list))
			ft_expand_token_string(token_list);
		token_list = token_list->next;
	}
}
