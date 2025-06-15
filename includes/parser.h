/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:16:27 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/15 03:30:14 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_quotes
{
	int	single_count;
	int	double_count;
	int	is_single_quote;
	int	is_double_quote;
}		t_quotes;

typedef struct s_index
{
	int	val;
	int	match;
	int	env;
	int	found_match;
	int	last_match_len;
}		t_index;

void	ft_double_quotes(t_token *argument, char *outcome, int *i, int *index);
void	ft_single_quotes(t_token *argument, char *outcome, int *i, int *index);

char	*ft_filter_quotes(t_token *argument);
int		ft_closed_quotes(t_token *input);

int		ft_find_end(char *input, int *is_space, int *in_end);

void	ft_setting_types(t_token *input, char **env);
void	ft_filtering_spaces(t_token *temp);
void	ft_initialise_nodes(t_token *list);

t_token	*ft_edit_input(char *input);
t_token	*ft_parsing(char *ret, char **env);

void	ft_expand_all_tokens(t_token *input);
void	ft_expand_token_string(t_token *token);
void	ft_expand_token_value(t_token *token, t_index *index);
void	ft_expand_without_match(t_token *token, t_index *index);
void	ft_expand_with_match(t_token *token, t_index *index);

#endif