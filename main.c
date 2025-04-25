/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:53:26 by sohamdan          #+#    #+#             */
/*   Updated: 2025/04/25 10:18:56 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/history.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft.h"


		// ------------------------------- Parsing Plan -------------------------------
		// [1] Tokenisation:
			// Split the input string by spaces while respecting quotes.
			// Store the resulting tokens in a linked list.

		// [2] Quote Validation:
			// Check if quotes (single and double) are balanced (i.e., appear in pairs).
			// If not balanced: throw a syntax error and prompt again.

		// [3] Quote Processing:
			// For tokens with double quotes:
				// If quotes are balanced:
					// Check if the quoted content contains a '$' symbol.
						// If not, remove the quotes and treat as a literal.
						// If yes, mark it as expandable for variable substitution.
				// If not balanced: error handled above.

			// Repeat the same check for single quotes:
				// Remember: variables inside single quotes are *not* expanded.

		// [4] Token Categorisation:
			// For each token:
				// Identify whether it's:
					// a command (likely the first token)
					// an option (starts with '-')
					// a file or path (contains '/', or detected during redirection)
					// a redirection operator ('>', '>>', '<', '<<')
					// a pipe symbol ('|')

		// [5] (Later) Build a Command Table or Abstract Syntax Tree (AST) from the tokens.

int	main(void)
{
	char	*input;

	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			break;
		add_history(input);
	}
}

