/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:16:27 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/30 00:45:10 by sohamdan         ###   ########.fr       */
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

void	double_quotes(t_token *argument, char *outcome, int *i, int *index);
void	single_quotes(t_token *argument, char *outcome, int *i, int *index);

char	*ft_filter_quotes(t_token *argument);
int		ft_closed_quotes(t_token *input);

int		ft_find_end(char *input, int *is_space, int *in_end);

void	ft_setting_types(t_token *input);
void	ft_filtering_spaces(t_token *temp);

t_token	*ft_edit_input(char *input);
t_token	*parsing(char *ret, char **env);

#endif