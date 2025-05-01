/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:45:11 by sohamdan          #+#    #+#             */
/*   Updated: 2025/04/29 11:08:39 by sohamdan         ###   ########.fr       */
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
	(*new_node).next = NULL;
	return (new_node);
}

t_token	*ft_last_node(t_token *lst)
{
	t_token	*current;
	t_token	*previous;

	if (!lst)
		return (NULL);
	current = lst;
	previous = current;
	while (current != NULL)
	{
		current = (*current).next;
		if (current != NULL)
			previous = current;
	}
	return (previous);
}

void	ft_add_node_front(t_token **lst, t_token *new)
{
	if (new)
	{
		(*new).next = *lst;
		(*lst) = new;
	}
}

void	ft_add_node_back(t_token **lst, t_token *new)
{
	t_token	*current;

	if ((*lst) == NULL)
		ft_add_node_front(lst, new);
	else
	{
		current = ft_last_node((*lst));
		(*current).next = new;
	}
}
