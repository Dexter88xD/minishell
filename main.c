/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:53:26 by sohamdan          #+#    #+#             */
/*   Updated: 2025/04/27 11:52:07 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main(int argc, char **argv, char **envp)
{
	char	*ret;
	char	*input;
	int		check;

	input = readline("minishell$: ");
	if (!input)
	{
		free(input);
		return (1);
	}
	add_history(input);
	ret = ft_strchr(input, '-');
	if (ret)
	{
		
		check = ft_strncmp(ret, "-n", 2);
		if (!check)
		{
			printf("hna\n");
			ret = ft_strtrim(input, "echo -n");
			printf("%s", ret);
			ft_echo(ret, 1);
		}
		else
		{
			printf("lhih\n");
			ret = ft_strtrim(input, "echo");
			ft_echo(ret, 0);
		}
	}
	(void)argc;
	(void)argv;
	(void)envp;
	return (0);
}