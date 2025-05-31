/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:18:05 by kakbour           #+#    #+#             */
/*   Updated: 2025/05/30 17:48:04 by sohamdan         ###   ########.fr       */
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

const char	*token_type_to_str(t_type type)
{
	static const char	*names[] = {"UNKNOWN", "CMD", "ARG", "OPERATOR"};

	return (names[type]);
}

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
		input = parsing(ret);
		if (!input)
		{
			free(ret);
			continue ;
		}
		input->env = env;
		excution(input);
		free(ret);
	}
	return (0);
	(void)ac;
	(void)av;
}

// temp = input;
// while (temp)
// {
// 	printf("\n");
// 	printf("node : ~%s~\nwith type: %s\n", (char *)temp->value,
// 		token_type_to_str(temp->type));
// 	temp = temp->next;
// }
