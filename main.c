/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:53:26 by sohamdan          #+#    #+#             */
/*   Updated: 2025/04/25 16:04:11 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "minishell.h"

//Notes:
// Dexter: Found issue with this approach: if the case of \\\ echo "     test"  /// 
			// the split step will ignore the spaces inside the double quotes, which should not ignore them.
			// We need to reorganise the steps to address this issue!

// Khalid: 
			
// ------------------------------- Parsing Plan -------------------------------
// [1] Tokenisation:
// - Split the input string into tokens, respecting quotes (single and double).
// - Store each token in a linked list (t_token).

// [2] Quote Validation:
// - Ensure that all quotes are properly closed (balanced).
// - If quotes are unbalanced: return a syntax error and reprompt.

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

typedef	struct s_token
{
	char			*value;
	int				type;
	struct s_token	*next;
} t_token;


int	main(void)
{
	char	*input;
	// char	**temp;
	// t_token	*tokens = NULL;
	int		i;

	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			break ;
		add_history(input);
		i = 0;
		while (input[i])
		{
			//if input[i] == space
				//copy the string before 
			//if input[i] == tab
			//if input[i] == new line
			//if input[i] == dollar sign
			//if input[i] == double quotes
				//copy the content until the next double "quotes"
			//if input[i] == single quotes
			//if input[i] == redirection (input or output)
			//if input[i] == here-doc
			//if input[i] == pipe
		}
	}
}
