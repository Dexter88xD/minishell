/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:18:05 by kakbour           #+#    #+#             */
/*   Updated: 2025/05/01 11:44:41 by sohamdan         ###   ########.fr       */
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

#include "minishell.h"
#include "builtin.h"
#include "env.h"
#include "executor.h"
#include "libft.h"
#include "parser.h"
#include "signals.h"
#include "utils.h"

int	main(void)
{
	char		*input;
	t_token		*first_input;

	while (1)
	{
		input = readline("minishell$ ");
		add_history(input);
		first_input = ft_edit_input(input);
		while (first_input)
		{
			printf("node: >%s<\n", (char *)first_input->value);
			first_input = first_input->next;
		}
	}
	return (0);
}
