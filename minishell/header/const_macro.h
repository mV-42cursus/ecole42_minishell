/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_macro.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 02:40:15 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 02:43:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_MACRO_H
# define CONST_MACRO_H

# define DOUBLE_QUOTE '\"'
# define SINGLE_QUOTE '\''
# define REGULAR_STR 13
# define EXPANSION '$'
# define EXPANSION_ARG 'A'
# define INPUT_REDIRECTION "<"
# define OUTPUT_REDIRECTION ">"
# define HEREDOC_INPUT "<<"
# define HEREDOC_OUTPUT ">>"
# define BUFFER_SIZE 42

# define IGN 1
# define DFL 2
# define SHE 3
# define HEREDOC 4

# define PIPE '|'

# define MET_SPACE 1

# define TRUE 1
# define FALSE 0

# define STOP -1

# define DISPLAY 1
# define NO_DISPLAY 0

# define START 0
# define END 1

# define PIPE_CNT 2

# define CNT 2

# define ROTATION 0
# define _CNT 1

# define REDIRECTION_TYPE 'T'
# define REDIRECTION_ARGUMENT 'A'
# define EXECUTION 'C'

# define ERR_NO_FILE 1
# define ERR_NO_CMD 2
# define ERR_KEY_NAME 3
# define ERR_NAME_LONG 4
# define ERR_IS_DIR 5
# define ERR_MAX_HERE_DOC 6
# define ERR_CD_DIR 7
# define ERR_EXIT_NO_NUM 8
# define ERR_EXIT_ARG 9

enum e_class {
	PIPELINE=0,
	CMD,
	REDIRECTS,
	SIMPLE_CMD,
};

enum e_parse {
	COMMAND=0,
	REDIRECTION,
	ARGUMENT,
};

enum e_redirection {
	IN_FILE,
	IN_HEREDOC,
	OUT_FILE,
	OUT_HEREDOC,
};

enum e_signal {
	DEFAULT_SUCCESS,
	SYNTAX_ERROR = 258,
};

#endif