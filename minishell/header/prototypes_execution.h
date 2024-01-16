/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes_execution.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongolee <jongolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 02:42:28 by marvin            #+#    #+#             */
/*   Updated: 2023/10/10 18:11:32 by jongolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_EXECUTION_H
# define PROTOTYPES_EXECUTION_H

# include "library_headers.h"

void				signal_handler(int sig);

int					do_simple_cmd(t_class *node, int *pipe_fd);
void				free_split(char **result);
void				add_local_history(char *input);
void				err_fd_fork_pipe_dup(int i);
void				ft_perror(void);

void				ft_strerror(char *str, int errno);
void				on_exit_signal(void);

int					pre_order_execution(t_class *node, int *pipe_fd);

//cmd list
int					do_exit(t_class *node);
int					do_history(void);
int					do_cd(t_class *node);
int					do_unset(t_class *node);
int					str_cmp(char *s1, char *s2);
int					do_echo(t_class *node, int i, int j);
int					do_pwd(void);
int					do_export(t_class *node, int is_failed);
int					do_env(t_class *node);
int					check_key_name(char *key, char *cmd, int errno);
void				set_signal(int sig_int, int sig_quit);
void				init_term(void);
void				reset_term(void);
void				wait_child(void);
int					get_here_doc(t_class *node);
char				**set_envp(t_env *lst);
void				remove_dir(void);
void				push_equal_cmd(t_class *node, int *i);
void				count_here_doc(t_class *node, int *count);

void				do_absolute_path(char *cmd, char **args, char **envp);
void				do_execve(t_class *node, int i, int j);
int					do_built_in(t_class *node);
void				add_key_to_env(t_class *node, t_env *env, int i, char *key);

int					do_set(t_class *node);
int					check_set(t_class *node);
int					do_simple_cmd(t_class *node, int *pipe_fd);

char				**set_envp(t_env *lst);
char				*path_value_exists(t_env *env_lst);
char				**make_new_args(char **args, char *cmd, int size, int j);
int					is_path(char *cmd);
int					str_cmp(char *s1, char *s2);
int					is_have_equal(char *cmd);
int					do_env(t_class *node);
int					do_history(void);
int					do_pipe(t_class *node, int *pipe_fd);
int					do_cmd(t_class *node, int *pipe_fd);

int					infile_red(int *fd, t_redirection *_red_lst);
int					append_red(int *fd, t_redirection *_red_lst);
int					outfile_red(int *fd, t_redirection *_red_lst);
int					heredoc_red(int *fd, t_redirection *_red_lst);
int					check_outfile(char *src, int i);
void				here_doc_counter(t_class *node, int *count);
void				count_here_doc(t_class *node, int *count);
void				make_dir(t_class *node);
void				make_here_doc_file_sub(int *fd, t_redirection *red);
char				*expand_heredoc(char *str, t_dollar **dollar_lst, \
									t_env *envp_lst, int i);
char				*heredoc_str_expansion(char *str, t_dollar **dollar_lst, \
										t_env *envp_lst);
void				env_lst_update(t_class *node, t_env *env, \
									char *cmd, char *key);

// PARSE
void				free_str(char **str);
void				free_char_double_pointer(char ***arr);
#endif