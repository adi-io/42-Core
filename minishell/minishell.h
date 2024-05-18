/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:05:35 by mman              #+#    #+#             */
/*   Updated: 2024/04/28 14:51:36 by mman             ###   ########.fr       */
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

int		handle_quotes(int i, char *str, int c);
int		read_words(int i, char *str, t_lexer **lexer_list);
int		find_other_pair(char *str, int i, int *int_del, int del);
int		count_quotes(char *str);
int		minishell_loop(t_tools *tools);
int		parser(t_tools	*tools);

void		ft_count_pipes(t_lexer *lexer_list, t_tools *tools);
t_simple_cmds	*init_cmd(t_parser_tools *parser_tools);
void		rm_redirections(t_parser_tools *parser_tools);
int		add_new_redirection(t_lexer *tmp, t_parser_tools *parser_tools);

int		token_reader(t_tools *tools);
int		handle_token(char *str, int i, t_lexer **lexer_list);
t_tokens	check_token(int c);

int		add_node(char *str, t_tokens token, t_lexer **lexer_list);
char		**ft_memmory(char **ptr);
int		init_tools(t_tools *tools);
int		find_pwd(t_tools tools);
char		*find_path(char **envp);
int		parse_envp(t_tools *tools);

t_lexer		*ft_rem_lexstr(t_lexer **lexer_list);
void		ft_rem_first(t_lexer **lexer_list);
void		ft_rm_lex(t_lexer **lexer_list, int key);
t_lexer		*ft_lexernew(char *str, int token);
void		ft_lexaddback(t_lexer **lst, t_lexer *new);
t_simple_cmds	*ft_simple_cmdnew(char	**str, int num_redirections
					, t_lexer *redirections);
void		ft_simple_cmd_addback(t_simple_cmds **lst, t_simple_cmds *new);

int		executer_enter(t_tools *tools);
int		executer(t_tools *tools);
t_simple_cmds	*ft_simple_cmdsfirst(t_simple_cmds *list_of_cmds);
int		simple_executer_single(t_simple_cmds *cmd, t_tools *tools);
t_simple_cmds	*expand_argument_call(t_tools *tools, t_simple_cmds *cmd);
void		execute_command(t_simple_cmds *cmd, t_tools *tools);
int		check_redirections(t_simple_cmds *cmd);
int		fetch_func(t_simple_cmds *cmd, t_tools *tools);
int		cmd_not_found(char *str);


int	mini_cd(t_tools *tools, t_simple_cmds *simple_cmd);


int	(*builtin_arr(char *str))(t_tools *tools, t_simple_cmds *simple_cmd);

//ADDING PROTOTYPES NOTE23/04/
int		ft_error(int error, t_tools *tools);
void		reset_tools(t_tools *tools);
char	**resplit_str(char **double_arr);


//TOOLS FOR BUGCATCHING
void		envpprint(t_tools tools);

char	*delete_quotes(char *str, char c);
size_t	quotes_length(char *str);
int	after_dol_lenght(char *str, int i);
char	*char_to_str(char c);
size_t	dollar_sign(char *str);
int	question_mark(char **tmp);

char	**expander(t_tools *tools, char **str);
char	*expand_str(t_tools *tools, char *str);
char	*detect_dollar_sign(t_tools *tools, char *str);
int	handle_digit_after_dollar(int j, char *str);
int	loop_if_dollar_sign(t_tools *tools, char *str, char **tmp, int j);

#endif
