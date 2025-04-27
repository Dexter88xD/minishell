/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakbour <kakbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:14:36 by sohamdan          #+#    #+#             */
/*   Updated: 2025/04/27 15:24:15 by kakbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include <readline/history.h>
# include <readline/readline.h>

# include <sys/types.h>
# include <sys/wait.h>

# include "builtin.h"
# include "env.h"
# include "executor.h"
# include "libft.h"
# include "parser.h"
# include "signals.h"
# include "utils.h"

typedef	struct s_token
{
	char			*value;
	int				type;
	struct s_token	*next;
} t_token;

#endif
