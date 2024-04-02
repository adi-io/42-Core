#include "minishell.h"

typedef struct s_tools
{
	char					*args;
	char					**paths;
	char					**envp;
//	struct s_simple_cmds	*simple_cmds;
	t_lexer					*lexer_list;
	char					*pwd;
	char					*old_pwd;
	int						pipes;
	int						*pid;
	bool					heredoc;
	bool					reset;
}	t_tools;

