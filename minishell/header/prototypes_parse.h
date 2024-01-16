/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes_parse.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 02:42:02 by marvin            #+#    #+#             */
/*   Updated: 2023/11/29 00:11:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_PARSE_H
# define PROTOTYPES_PARSE_H

# include "./library_headers.h"

/* HEAP */
// heap_1.c
void				free_str(char **str);
void				free_tokens(t_token *token);
void				free_int_double_array(int row, int **array);
void				free_char_double_pointer(char ***arr);

// heap_2.c
void				env_lstclear(t_env **lst, void (*del)(char **));
void				redirection_lstclear(t_redirection **lst, \
												void (*del)(char **));
void				dollar_lstclear(t_dollar **lst, void (*del)(char **));

// heap_3.c
void				free_pipe(t_class **node);
void				free_cmd(t_class **node);
void				free_redirect(t_class **node);
void				free_simple_cmd(t_class **node);
void				pre_order_free(t_class **node);

/* UTILS */
// ast_utils.c
char				*ft_parser(t_class *child, int flag);
void				quote_push_quote(char *parser, char *ret, \
									int *i, char status);
char				*quote_info(char *parser, int i, char status, int len);
int					should_remove(char c, char *str, char type, int i);
char				*dollar_removal(char *str, int i, \
									char **quote_lexer, int *removed);

//here_doc_utils.c
char				*ft_heredoc_parser(char *src, char *parser, \
										int *lexer, int flag);

// lst_dollar_1.c
t_dollar			*dollar_lstlast(t_dollar *lst);
void				dollar_lstadd_back(t_dollar **lst, t_dollar *new);
t_dollar			*dollar_lstnew(char *str, char *lexer, int i);
struct s_dollar		*create_dollar_lst(char *parser, char *lexer, int i);

// lst_dollar_2.c
char				*determine_arg(char *s, char *ret, int i, int k);
char				*dollar_determine_arg(char *s, int i, int len, int k);

// lst_env_1.c
void				env_lstadd_back(t_env **lst, t_env *new);
t_env				*env_lstlast(t_env *lst);
t_env				*env_lstnew(char *envp);
char				*env_search_value_lst(t_env *env_lst, char *key, \
											int (*cmp)());
struct s_env		*create_environment_lst(char **envp);

// lst_env_2.c
char				*preprocess_value(char *str, int *i);
void				preprocess_envp_value(char **str, int i);
char				*determine_key(char *envp);
char				*determine_value(char *envp);

// lst_export_1.c
void				export_lstadd_back(t_export **lst, t_export *new);
t_export			*export_lstlast(t_export *lst);
t_export			*export_lstnew(char *str);
t_export			*create_export_lst(t_env *envp_lst);

// lst_export_2.c
void				allocate_values(t_env *begin_list, void	*temp_src, \
									void	*temp_key, void	*temp_value);
char				*create_export_value(char *key, char *value);
void				env_lst_sort(t_env **begin_list, \
								int (*cmp)(const char *, const char *));
void				export_lst_sort(t_export **begin_list, \
									int (*cmp)(const char *, const char *));
// lst_redirection_1.c
void				redirection_lstadd_back(t_redirection **lst, \
											t_redirection *new);
t_redirection		*redirection_lstlast(t_redirection *lst);
t_redirection		*redirection_lstnew(t_token *type, t_token *arg, \
										char *arguments, int i);
t_redirection		*create_redirection_lst(char *redirections, \
										char *arguments);
t_redirection		*redirection_lst_init(t_class *left_child);

// lst_redirection_2.c
int					determine_type(char *type);
int					no_redirection(t_class *left_child);
char				*final_arg(char *arguments);

/* PARSE_DIR */
// ast_left.c
void				left_child_pipeline(t_queue *cmd_queue, \
										t_class *node, t_queue *queue);
void				left_child_cmd(t_queue *cmd_queue, t_class *node, \
									t_queue *queue);
void				create_left_child(t_class *node, t_queue *cmd_queue, \
									t_queue *queue);

// ast_right.c
void				right_child_pipeline(t_queue *cmd_queue, t_class *node, \
										t_queue *queue, t_env *env);
void				right_child_cmd(t_queue *cmd_queue, t_class *node, \
									t_queue *queue);
void				create_right_child(t_class *node, t_queue *cmd_queue, \
										t_queue *queue, t_env *env);

// ast.c
void				init_ast(t_class *root, t_queue **cmd_queue, t_env *env);

// expansion_cmd_1.c
char				*expand_cmd(char *str, t_dollar **dollar_lst, \
								t_env *envp_lst, int i);
char				**create_cmd_arr(t_token *tokens, int len, int i);
char				**cmd_expansion(t_token *tokens, t_dollar *dollar_lst, \
									t_env *envp_lst);

// expansion_cmd_2.c
char				*exit_status_expansion(char **str, char *key);
void				value_not_found_case(char **str, char *key, \
										int i, t_dollar **dollar_lst);
void				value_found_case(char **str, char *value, \
								int i, t_dollar **dollar_lst);
void				regular_case(char **str, int i, t_dollar **dollar_lst, \
								t_env *envp_lst);
void				double_quote_case(char **str, int i, t_dollar **dollar_lst, \
								t_env *envp_lst);

// expansion_redirection.c
char				*expand_redirection(char *str, t_dollar **dollar_lst, \
										t_env *envp_lst, int i);
void				redirection_expansion(t_redirection *redirection_lst, \
										t_dollar *dollar_lst, t_env *envp_lst);

// lexer_1.c
int					is_redirection_type(int *lexer, char *input, int *i);
void				redirection_arg_idx(int *lexer, int *_data, \
											char *input, char *type);
void				redirection_type_idx(char *input, int *lexer);
int					*idx_info(char *input);

// lexer_2.c
void				push(int *lexer, int *i, char *input, char *type);
void				hasing_redirection_argument(int *lexer, \
											char *input, int *i, char *type);

// main.c
int					main(int ac, char **av, char **envp);

// queue_1.c
char				**queue_create_cmd(char *input, int *pipe_loc, \
									int pipe_cnt, char **cmd);
struct s_queue		*empty_pipe_error(char **input, int **pipe_loc);
void				queue_push(t_queue *queue, char **cmd);
struct s_queue		*init_queue(char *input, int pipe_cnt);

// queue_2.c
int					queue_count_pipeline(char *input);
void				queue_loc_pipeline(char *input, int *pipe_loc);

// syntax_1.c
void				syntax_quote_matching_idx(char *_input, int *i, char flag);
void				syntax_calculate_idx(int *start, int *end, char *_input);
char				*syntax_tr_quote(int start, int end, char *_input);
int					is_syntax_error(char *_input);
char				*syntax_preprocess_tr_quotes_space(char *_input);

// syntax_2.c
int					syntax_is_all_space(char *input);
int					syntax_error(char *input);
int					syntax_quote_check(char **input, int *i, char flag);
int					syntax_unclosed_quote(char *input);
void				syntax_calculate_idx2(int *data, int rot, int *pipe_loc, \
										char *input);

// syntax_3.c
int					syntax_empty_pipeline(char *input, int *pipe_loc, \
									int pipe_cnt);
int					syntax_count_redirections(char *str);
void				syntax_calculate_idx3(char *_input, \
										int **redirection_type_idx);
void				syntax_calculate_idx4(int **redirection_type_idx, \
										int rotation, char *input, int *data);
int					is_error(char *input, int i, int *data);

// syntax_4.c
int					export_value_syntax_error(char *cmd);
int					is_redirection_error(int **redirection_type_idx, \
										int redirection_cnt, char *input);
int					syntax_redirection_error(char *input);
int					syntax_white_space(char *input);
int					double_dollar(char *input);

// token_array_1.c
int					is_quote(char c, char *type);
void				quote_handler_word_cnt(char *line, int *i, char type, \
							char sep);
int					calculate_cnt(char *line, char sep, char type);
int					calculate_pointer(char *line, char sep, char type);
int					calculate_word_len(char *line, char sep, char type);

// token_array_2.c
char				*allocate_characters(char *line, char type, \
										char *str, char sep);
int					meta_character(char *line, int dest);
t_token				*create_token_arr(char *line, char sep, char type);
void				wait_heredoc(void);
#endif