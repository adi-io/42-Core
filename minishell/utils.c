/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:31:12 by agadkari          #+#    #+#             */
/*   Updated: 2024/04/11 17:31:29 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_memmory(char **ptr)
{
	size_t i;
	char	**new;

	i = 0;
	if (!ptr[i])
		return (NULL);
	new = ft_calloc(sizeof(char *), i + 1);
	while (ptr[i])
	{
		new[i] = ft_strdup(ptr[i]);
		//fail condition and free
		i++;
	}
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
	//init signals for later
	return (0);
}

int	find_pwd(t_tools *tools)
{
	int	i;

	i = 0;
	while (tools -> envp[i])
	{
		if (!ft_strncmp(tools -> envp[i], "PWD=", 4))
			tools -> pwd = ft_substr(tools -> envp[i], 4, ft_strlen(tools -> envp[i]) - 4);
		if (!ft_strncmp(tools -> envp[i], "OLDPWD=", 7))
			tools -> old_pwd = ft_substr(tools -> envp[i], 7, ft_strlen(tools -> envp[i]) - 7);
		i++;
	}
	return (0);
}

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH:", 5))
			return (ft_substr(envp[i], 5, ft_strlen(envp[i] - 5) ));
		i++;
	}
	return (strdup("\0"));
}

int	parse_envp(t_tools *tools)
{
	char	*path_from_envp;
	int	i;
	char	*temp;

	path_from_envp = find_path(tools -> envp);
	tools -> paths = ft_split(path_from_envp, ':');
	free(path_from_envp);
	i = 0;
	while(tools -> paths[i])
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
	return (0);
}
