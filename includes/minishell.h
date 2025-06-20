/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakbour <kakbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:14:36 by sohamdan          #+#    #+#             */
/*   Updated: 2025/06/20 12:57:18 by kakbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/history.h>
# include <readline/readline.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>

# include "libft.h"

# define NOT_MALLOCED	0
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
	char			**env;
	int				malloced;
	int				quotes;
	struct s_token	*previous;
	struct s_token	*next;
	t_type			type;
}	t_token;

#endif
