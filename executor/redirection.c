/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:49:06 by kakbour           #+#    #+#             */
/*   Updated: 2025/06/20 17:46:20 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	ft_stdin_redirect(t_token *input)
{
	int fd;

	fd = open(input->next->value, O_CREAT | O_RDWR | O_TRUNC, 0744);
	dup2(fd, 0);
	close(fd);
}
void	ft_stdout_redirect(t_token *input)
{
	int fd;

	fd = open(input->next->value, O_CREAT | O_RDWR | O_TRUNC, 0744);
	dup2(fd, 1);
	close(fd);
}

void	ft_open_files(t_token *input)
{
	while(input)
	{
		if (input->type == INPUT_RED)
			ft_stdin_redirect(input);
		else if (input->type == OUTPUT_RED)
			ft_stdout_redirect(input);
		input = input->next;
	}
}