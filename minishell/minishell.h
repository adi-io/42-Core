#ifndef MINISHELL_H
# define MINISHELL_H
#include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include "structs.h"
# include "./libft/includes/libft.h"

typedef struct s_global
{
	int	error_num;
	int	stop_heredoc;
	int	in_cmd;
	int	in_heredoc;
}	t_global;

t_global	g_global;

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

void		ft_rem_lexstr(t_lexer **lexer_list);
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
int		simple_executer_single(t_tools *tools);
t_simple_cmds	*expand_argument_call(t_tools *tools, t_simple_cmds *cmd);
int		execute_command(t_simple_cmds *cmd, t_tools *tools);



//ADDING PROTOTYPES NOTE23/04/
int		ft_error(int error, t_tools *tools);
void		reset_tools(t_tools *tools);


//TOOLS FOR BUGCATCHING
void		envpprint(t_tools tools);


#endif
