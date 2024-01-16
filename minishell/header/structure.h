/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 02:43:36 by marvin            #+#    #+#             */
/*   Updated: 2023/10/10 16:29:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "library_headers.h"

extern int	g_signal;

typedef struct s_token {
	int		type;
	char	*str;
	int		cnt;
}	t_token;

typedef struct s_redirection {
	int						type;
	char					*argument;
	char					*src;
	int						contaminated;
	struct s_redirection	*next;
}	t_redirection;

typedef struct s_dollar {
	char			status;
	char			*arg;
	struct s_dollar	*next;
}	t_dollar;

typedef struct s_env {
	char			*src;
	char			*key;
	char			*value;
	int				is_export;
	struct s_env	*next;
}	t_env;

typedef struct s_export {
	char			*src;
	struct s_export	*next;
}	t_export;

typedef struct s_class {
	int				type;
	char			*src;
	int				*lexer;
	char			*parser;
	char			**cmd_arr;
	struct s_env	*envp_lst;
	t_redirection	*redirection_lst;
	t_token			*tokens;
	struct s_class	*l_child;
	struct s_class	*r_child;
}	t_class;

#endif