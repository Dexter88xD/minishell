/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:16:45 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/14 21:47:15 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

const char	*ft_token_type_str(t_type type);

int			ft_isspace(int c);
int			ft_operator(char *str);
int			ft_check_integer(char *input);

t_token		*ft_new_node(void *content, int malloced);
t_token		*ft_last_node(t_token *lst);

void		ft_add_node_front(t_token **lst, t_token *new);
void		ft_add_node_back(t_token **lst, t_token *new);
void		ft_del_node(t_token **node);
void		ft_del_lst(t_token *node);

int			ft_size_lst(t_token *lst);

#endif