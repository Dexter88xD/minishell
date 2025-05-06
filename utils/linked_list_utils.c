/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:45:11 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/05 11:08:14 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"

t_token	*ft_new_node(void *content)
{
	t_token	*new_node;

	new_node = (t_token *)malloc(sizeof(t_token));
	if (!new_node)
		return (NULL);
	(*new_node).value = content;
	(*new_node).type = 0;
	(*new_node).previous = NULL;
	(*new_node).next = NULL;
	return (new_node);
}

void	ft_add_node_front(t_token **lst, t_token *new)
{
	if (!new)
		return ;
	if (*lst)
	{
		new->next = *lst;
		(*lst)->previous = new;
	}
	new->previous = NULL;
	*lst = new;
}

void	ft_add_node_back(t_token **lst, t_token *new)
{
	t_token	*current;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->previous = NULL;
	}
	else
	{
		current = ft_last_node(*lst);
		current->next = new;
		new->previous = current;
	}
}

t_token	*ft_last_node(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
