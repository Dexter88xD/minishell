/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakbour <kakbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:18:05 by kakbour           #+#    #+#             */
/*   Updated: 2025/06/20 16:50:43 by kakbour          ###   ########.fr       */
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

//need to handle errors of invalid read size in the case of echo $HOMEasdf
//need to handle unexpected outcome in the case of echo $pp$HOME

char *token_type_to_str(int type)
{
	char *a;
	
	if (type == 1)
		a = "cmd";
	if (type == 2)
		a = "arg";
	if (type == 3)
		a = "operator";
	return (a);
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
		input = ft_parsing(ret, env);
		if (!input)
		{
			free(ret);
			continue ;
		}
		// t_token	*temp;

		// temp = input;
		// while (temp)
		// {
		// 	printf("\n");
		// 	printf("node : ~%s~\nwith type: %s\n", (char *)temp->value, token_type_to_str(temp->type));
		// 	temp = temp->next;
		// }
		int pid = fork();
		if(pid == 0)
		{	
			ft_excution(input);
			exit(0);
		}
		wait(NULL);
		free(ret);
	}
	(void)ac;
	(void)av;
	return (0);
}