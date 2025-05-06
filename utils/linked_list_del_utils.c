/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_del_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:45:11 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/05 11:23:25 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"

void	ft_del_lst(t_token *node)
{
	t_token	*temp;

	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
}

void	ft_del_node(t_token *node)
{
	if (!node)
		return ;
	if (node->next && node->previous)
	{
		node->previous->next = node->next;
		node->next->previous = node->previous;
	}
	else
	{
		if (!node->next && node->previous)
			node->previous->next = NULL;
		if (!node->previous && node->next)
			node->next->previous = NULL;
	}
	free(node);
}
