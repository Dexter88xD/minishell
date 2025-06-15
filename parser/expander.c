/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:07:42 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/15 03:29:47 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"
#include "utils.h"

void	ft_expand_with_match(t_token *token, t_index *index)
{
	char	*prefix;
	char	*suffix;
	char	*env_val;

	prefix = ft_strndup(token->value, index->val);
	env_val = token->env[index->env] + index->match + 1;
	suffix = ft_strjoin(env_val, token->value + index->val + index->match + 1);
	free(token->value);
	token->value = ft_strjoin(prefix, suffix);
	if (prefix)
		free(prefix);
	if (suffix)
		free(suffix);
	index->val += ft_strlen(env_val) - 1;
}

void	ft_expand_without_match(t_token *token, t_index *index)
{
	char	*prefix;
	char	*suffix;
	int		name_len;

	prefix = ft_strndup(token->value, index->val);
	name_len = ft_var_name_length(token->value + index->val + 1);
	suffix = token->value + index->val + name_len + 1;
	free(token->value);
	token->value = ft_strjoin(prefix, suffix);
	if (prefix)
		free(prefix);
	index->val += index->last_match_len + ft_var_name_length(suffix
			+ index->last_match_len + index->val) - 1;
}

void	ft_expand_token_value(t_token *token, t_index *index)
{
	if (index->found_match)
		ft_expand_with_match(token, index);
	else
		ft_expand_without_match(token, index);
}

void	ft_expand_token_string(t_token *token)
{
	t_index	*index;

	index = malloc(sizeof(t_index));
	index->val = 0;
	index->match = 0;
	index->last_match_len = 0;
	while (token->value[index->val])
	{
		index->env = 0;
		index->found_match = 0;
		if (token->value[index->val] == '$')
		{
			ft_find_env_match(token, index);
			ft_expand_token_value(token, index);
		}
		else
			index->val++;
		if (index->val < 0)
			index->val = 0;
	}
	free(index);
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
