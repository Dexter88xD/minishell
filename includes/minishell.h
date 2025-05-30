/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:14:36 by sohamdan          #+#    #+#             */
/*   Updated: 2025/05/30 16:19:11 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/history.h>
# include <readline/readline.h>
# include <sys/types.h>
# include <sys/wait.h>

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>

# include "libft.h"

# define MALLOCED		1
# define SINGLE_QUOTES	2
# define DOUBLE_QUOTES	3

typedef enum e_type
{
	CMD = 1,
	ARG = 2,
	OPERATOR = 3
}	t_type;

typedef struct s_token
{
	char			*value;
	t_type			type;
	int				malloced;
	int				quotes;
	char			**env;
	struct s_token	*previous;
	struct s_token	*next;
}	t_token;

#endif
