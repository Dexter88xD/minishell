/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:16:27 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/28 21:52:51 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

int		ft_find_end(char *input, int *is_space, int *in_end);

void	ft_setting_types(t_token *input);
void	ft_filtering_spaces(t_token *temp);

t_token	*ft_edit_input(char *input);
t_token	*parsing(char *ret);

#endif