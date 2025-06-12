/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:18:05 by kakbour           #+#    #+#             */
/*   Updated: 2025/06/12 17:06:25 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env.h"
#include "executor.h"
#include "libft.h"
#include "minishell.h"
#include "parser.h"
#include "signals.h"
#include "utils.h"

int	main(int ac, char **av, char **env)
{
	char	*ret;
	t_token	*input;

	input = NULL;
	while (1)
	{
		ret = readline("minishell$ ");
		if (input)
			ft_del_lst(input);
		if (!ret)
			exit(1);
		add_history(ret);
		input = parsing(ret, env);
		if (!input)
		{
			free(ret);
			continue ;
		}
		excution(input);
		free(ret);
	}
	(void)ac;
	(void)av;
	return (0);
}
	// t_token	*temp;

	// temp = input;
		// while (temp)
		// {
		// 	printf("\n");
		// 	printf("node : ~%s~\nwith type: %s\n", (char *)temp->value,
		// 		token_type_to_str(temp->type));
		// 	temp = temp->next;
		// }