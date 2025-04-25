/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:14:36 by sohamdan          #+#    #+#             */
/*   Updated: 2025/04/25 11:34:52 by sohamdan         ###   ########.fr       */
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

#endif
