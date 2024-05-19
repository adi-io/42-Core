/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:31:12 by agadkari          #+#    #+#             */
/*   Updated: 2024/05/19 03:34:14 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_memmory(char **ptr)
{
	size_t	i;
	char	**new;

	i = 0;
	if (!ptr[i])
		return (NULL);
	while (ptr[i])
		i++;
	new = malloc(sizeof(char *) * i + 1);
	i = 0;
	while (ptr[i] != NULL)
	{
		new[i] = ft_strdup(ptr[i]);
		i++;
	}
	if (ptr[i] == NULL)
		new[i] = NULL;
	return (new);
}

int	init_tools(t_tools *tools)
{
	tools -> lexer_list = NULL;
	tools -> pid = NULL;
	tools -> heredoc = false;
	tools -> reset = false;
//	g_global.stop_heredoc = 0;
//	g_global.in_cmd = 0;
//	g_global.in_heredoc = 0;
	parse_envp(tools);
	find_pwd(tools);
	printf("to exit, press ctrl + c  OR   execute 'exit' \n");
	//init signals for later
	return (0);
}

//Finds PWD and OLD_PWD using the getenv func.
//Stores them to tools.pwd & tools.old_pwd
int	find_pwd(t_tools *tools)
{
	// char	*env_pwd;
// 	char	*env_old_pwd;
	int		i;

	i = 0;
	// // editing this 23/04/2024 MMAN -- its possible to use the getenv func. instead NOTE
	while (tools->envp[i])
	{
		if (!ft_strncmp(tools->envp[i], "PWD=", 4))
			tools->pwd = ft_substr(tools->envp[i], 4, ft_strlen(tools->envp[i]) - 4);
		if (!ft_strncmp(tools->envp[i], "OLDPWD=", 7))
			tools->old_pwd = ft_substr(tools->envp[i], 7, ft_strlen(tools->envp[i]) - 7);
		if (!ft_strncmp(tools->envp[i], "LOGNAME=", 8))
			tools->logname = ft_substr(tools->envp[i], 8, ft_strlen(tools->envp[i]) - 4);
		i++;
	}
	// // couldnt find PWD= records, NOTE
	// env_old_pwd = getenv("OLDPWD");
	// tools.pwd = ft_strdup(getenv("PWD"));
	// // tools.old_pwd = ft_strdup(env_old_pwd);
	// printf("PWD %s\n", tools.pwd);
	// printf("OLDPWD : %s", tools.old_pwd);
	printf("pwd is %s\n\n", tools->pwd);
	return (0);
}

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH:", 5) == 0)
			return (ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5));
		i++;
	}
	return (strdup("\0"));
}

//functions takes in the path and parses it into a digestable route "chunks"
int	parse_envp(t_tools *tools)
{
	char	*path_from_envp;
	int		i;
	char	*temp;

	path_from_envp = getenv("PATH");
	tools -> paths = ft_split(path_from_envp, ':');
	i = 0;
	while (tools -> paths[i])
	{
		if (ft_strncmp(&tools->paths[i][ft_strlen(tools->paths[i]) - 1],
			"/", 1) != 0)
		{
			temp = ft_strjoin(tools -> paths[i], "/");
			free(tools -> paths[i]);
			tools -> paths[i] = temp;
		}
		i++;
	}
	// //section for testing:
	// i = 0;
	// while (tools -> paths[i])
	// {
	// 	printf("%i, | path: %s\n", i, tools->paths[i]);
	// 	i++;
	// }
	return (0);
}
