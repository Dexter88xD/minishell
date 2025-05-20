/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:18:05 by kakbour           #+#    #+#             */
/*   Updated: 2025/05/20 16:58:49 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Notes:

// ------------------------------- Parsing Plan -------------------------------
// [1] Tokenisation:
// - Split the input string into tokens, respecting quotes (single and double).
// - Store each token in a linked list (t_token).

// [2] Quote Validation:
// - Ensure that all quotes are properly closed (balanced).
// - If quotes are unbalanced: return a syntax error.

// [3] Quote & Expansion Handling:
//- For tokens wrapped in double quotes:
// - Remove the quotes.
// - If they contain '$', mark the token as expandable (for variable expansion).
//- For tokens in single quotes:
// - Remove the quotes.
// - Do NOT expand variables inside single quotes (treat content as literal).

// [4] Token Classification:
//- Categorise each token in the linked list as one of:
// - COMMAND      → typically the first word
// - ARGUMENT     → follows a command
// - OPTION       → starts with '-'
// - REDIRECTION  → '>', '>>', '<', '<<'
// - PIPE         → '|'
// - FILENAME     → token after a redirection
//- This prepares for command structure building.

// [5] Build the Command Table:
//- Convert the token list into a linked list of commands (t_command).
//- Each node represents a command with its:
// - arguments
// - redirections
// - and pipe info.

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

int	main(void)
{
	char	*ret;
	t_token	*input;
	t_token	*temp;

	while (1)
	{
		ft_memset(&input, 0, sizeof(t_token *));
		ft_memset(&temp, 0, sizeof(t_token *));
		ret = readline("minishell$ ");
		if (!ret)
			break ;
		add_history(ret);
		input = ft_edit_input(ret);
		temp = input;
		ft_filtering_spaces(temp);
		ft_setting_types(temp);
		while (temp)
		{
			printf("\n");
			printf("node : ~%s~\nwith type: %s\n", (char *)temp->value,
				token_type_to_str(temp->type));
			temp = temp->next;
		}
		temp = input;
		while (temp)
		{
			if (!ft_strcmp(temp->value, "echo"))
				if (temp->next)
					ft_echo(temp->next);
			if (!temp->next)
				break ;
			temp = temp->next;
		}
	}
	return (0);
}
