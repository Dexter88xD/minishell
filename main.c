/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakbour <kakbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:53:26 by sohamdan          #+#    #+#             */
/*   Updated: 2025/04/27 14:47:26 by kakbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "minishell.h"

// Found issue with this approach: if the case of \\\ echo "     test"  /// 
// the split step will ignore the spaces inside the double quotes, which should not ignore them.
// We need to reorganise the steps to address this issue!

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

// char *recognizer(char c, char next)
// {
// 	if (c == '<')
// 	{
// 		if(next == '<')
// 			return("<<");
// 		return ("<");
// 	}
// 	else if (c == '>')
// 	{
// 		if(next == '>')
// 			return (">>");
// 		return (">");
// 	}
// 	else if (c == '|')
// 		return ("|");
// 	else
// 		return(NULL);
// }

// t_token *ft_return_tokens(char *input)
// {
// 	t_token *tokenazer;

// 	tokenazer = NULL;
// 	int i  = 0;
// 	while(input[i])
// 	{
// 		if(recognizer(input[i] , input[i + 1]))
			
			
// 	}
// }
// int ft_len(char *input)
// {
// 	int i = 1;
// 	int flag = 0;
// 	while(input[i] != '"' && input[i])
// 	{
// 		i++;
// 		if(input[i] == '"' && input[i])
// 		{
// 			if(input[i + 1] == ' ' && input[i])
// 			{
// 				flag = 1;
// 				return(i);
// 			}
// 			if(input[i + 1] != ' ' && input[i])
				
// 		}
// 	}
// }
// ls -la | echo "   test"test"   " | cat "  infile"
// result = ls -la | echo "   testtest   " | cat infile
char	*ft_edit_input(char *input)
{
	char	*edited_input = malloc(1025);
	int		is_find = 1;
	int		sisi = 1;
	int		i = 0;
	int		j = 0;
	while(input[i])
	{
		
		if(input[i] == '"' && sisi == 1)
			is_find = !is_find;
		else if(input[i] == '\'' && is_find == 1)
			sisi = !sisi;
		else
		{
			edited_input[j] = input[i];
			j++;
		}
		i++; 
	}
	if(!is_find || !sisi)
		return(write(1, "Syntax Error\n", 13) ,NULL);
	printf("-->%s\n", edited_input);
	return edited_input;
}
int	main(int argc, char **argv, char **env)
{
	char	*input;
	t_token	*tokens;
	char	*input_mise;
	
	(void)argv;
	(void)argc;
	(void)env;
	tokens = NULL;
	while (1)
	{
		input = readline("minishell$ ");
		input_mise = ft_edit_input(input);
		add_history(input);
	}
}

//<< >> < > | '\'' '\"'
//<< hello > file1 < file2  file infile 