/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_del_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:45:11 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/12 15:23:02 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"

void	ft_del_lst(t_token *node)
{
	t_token	*temp;

	while (node)
	{
		temp = node->next;
		if (node->malloced == MALLOCED)
			free(node->value);
		free(node);
		node = temp;
	}
}

void	ft_del_node(t_token **node)
{
	t_token	*temp;

	if (!node || !(*node))
		return ;
	temp = (*node);
	if ((*node)->next)
		(*node)->next->previous = (*node)->previous;
	if ((*node)->previous)
		(*node)->previous->next = (*node)->next;
	else
		(*node) = (*node)->next;
	if (temp->malloced)
		free(temp->value);
	free(temp);
}
