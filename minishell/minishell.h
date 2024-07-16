/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:05:35 by mman              #+#    #+#             */
/*   Updated: 2024/05/19 03:40:43 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/types.h>
# include "structs.h"
# include "./libft/libft.h"
# include "global.h"

# define FALSE 1

# define TRUE 0

# define HEREDOC_MSG	"\033[1;34m> \033[0m"

int				minishell_loop(t_tools *tools);
int				parser(t_tools	*tools);

int				implement_tools(t_tools *tools);
int				reset_tools(t_tools *tools);

int				parse_envp(t_tools *tools);
char			*find_path(char **envp);
int				find_pwd(t_tools *tools);

void			rm_redirections(t_parser_tools *parser_tools);
int				add_new_redirection(t_lexer *tmp, t_parser_tools *parser_tools);
char			*join_heredoc(char *str1, char *str2);
int				(*builtin_arr(char *str))(t_tools *tools,
					t_simple_cmds *simple_cmd);

int				token_reader(t_tools *tools);
int				read_words(int i, char *str,
					t_lexer **lexer_list, size_t str_len);
int				add_node(char *str, t_tokens token, t_lexer **lexer_list);
int				skip_spaces(char *str, int i);
int				is_whitespace(char c);

char			**ft_arrdup(char **arr);
int				count_quotes(char *line);
int				find_matching_quote(char *line, int i, int *num_del, int del);

void			ft_simple_cmdsclear(t_simple_cmds **lst);
void			ft_simple_cmds_rm_first(t_simple_cmds **lst);
void			ft_simple_cmdsadd_back(t_simple_cmds **lst, t_simple_cmds *new);

t_simple_cmds	*ft_simple_cmdsfirst(t_simple_cmds *map);
t_simple_cmds	*ft_simple_cmdsnew(char **str,
					int num_redirections, t_lexer *redirections);

void			ft_lexeradd_back(t_lexer **lst, t_lexer *new);
t_lexer			*ft_lexernew(char *str, int token);

void			ft_lexerclear(t_lexer **lst);
t_lexer			*ft_lexerclear_one(t_lexer **lst);
void			ft_lexerdel_first(t_lexer **lst);
void			ft_lexerdelone(t_lexer **lst, int key);

t_lexer			*find_next_cmd(t_lexer *lexer_lst);
int				count_args(t_lexer *lexer_list);
void			count_pipes(t_lexer *lexer_list, t_tools *tools);
t_parser_tools	init_parser_tools(t_lexer *lexer_list, t_tools *tools);

t_simple_cmds	*ft_simple_cmdsfirst(t_simple_cmds *map);
void			ft_simple_cmdsclear(t_simple_cmds **lst);
void			ft_simple_cmd_addback(t_simple_cmds **lst, t_simple_cmds *new);
t_simple_cmds	*ft_simple_cmdnew(char	**str,
					int num_redirections, t_lexer *redirections);

int				handle_quotes(int i, char *str, char del);
int				handle_token(char *str, int i, t_lexer **lexer_list);
t_tokens		check_token(int c);

//int	ft_execute_builtins(t_simple_cmds *cmd, t_tools *tools);
int				mini_cd(t_tools *tools, t_simple_cmds *simple_cmd);
int				mini_pwd(t_tools *tools);
int				mini_echo(t_tools *tools, t_simple_cmds *simple_cmd);
int				mini_export(t_tools *tools, t_simple_cmds *simple_cmd);
int				mini_exit(t_tools *tools, t_simple_cmds *simple_cmd);
int				mini_env(t_tools *tools, t_simple_cmds *simple_cmd);
int				mini_unset(t_tools *tools, t_simple_cmds *simple_cmd);

//builtin utils
int				check_valid_identifier(char c);
size_t			equal_sign(char *str);
void			free_arr(char **split_arr);

//ADDING PROTOTYPES NOTE23/04/
int				ft_error(int error, t_tools *tools);
int				reset_tools(t_tools *tools);
int				cmd_not_found(char *str);

//TOOLS FOR BUGCATCHING
void			envpprint(t_tools tools);

char			*delete_quotes(char *str, char c);
size_t			quotes_length(char *str);
int				after_dol_lenght(char *str, int i);
char			*char_to_str(char c);
size_t			dollar_sign(char *str);
int				question_mark(char **tmp);

char			**expander(t_tools *tools, char **str);
char			*expand_str(t_tools *tools, char *str);
char			*detect_dollar_sign(t_tools *tools, char *str);
int				handle_digit_after_dollar(int j, char *str);
int				loop_if_dollar_sign(t_tools *tools,
					char *str, char **tmp, int j);

//executer stuff
char			*join_split_str(char **split_str, char *new_str);
char			**resplit_str(char **double_arr);

int				send_heredoc(t_tools *tools, t_simple_cmds *cmd);
int				ft_heredoc(t_tools *tools, t_lexer *heredoc, char *file_name);
char			*generate_heredoc_filename(void);
int				create_heredoc(t_lexer *heredoc, bool quotes,
					t_tools *tools, char *file_name);

void			handle_cmd(t_simple_cmds *cmd, t_tools *tools);
void			dup_cmd(t_simple_cmds *cmd,
					t_tools *tools, int end[2], int fd_in);
void			single_cmd(t_simple_cmds *cmd, t_tools *tools);
int				find_cmd(t_simple_cmds *cmd, t_tools *tools);

t_simple_cmds	*call_expander(t_tools *tools, t_simple_cmds *cmd);
int				pipe_wait(int *pid, int amount);
int				ft_fork(t_tools *tools,
					int end[2], int fd_in, t_simple_cmds *cmd);
int				check_fd_heredoc(t_tools *tools,
					int end[2], t_simple_cmds *cmd);
int				executor(t_tools *tools);

int				check_redirections(t_simple_cmds *cmd);
int				handle_outfile(t_lexer *redirection);
int				handle_infile(char *file);
int				check_append_outfile(t_lexer *redirections);

//error stuff

int				ft_error(int error, t_tools *tools);
int				cmd_not_found(char *str);
void			lexer_error(int error, t_tools *tools);
int				export_error(char *c);
int				parser_double_token_error(t_tools *tools, t_lexer *lexer_list,
					t_tokens token);
void			parser_error(int error, t_tools *tools, t_lexer *lexer_list);

void			init_signals(void);
void			sigquit_handler(int sig);
void			sigint_handler(int sig);
int				event(void);

#endif
