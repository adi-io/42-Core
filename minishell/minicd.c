/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minicd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:09:50 by mman              #+#    #+#             */
/*   Updated: 2024/06/01 17:09:51 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup1(const char *s1)
{
	char	*s2;
	size_t	size;
	size_t	i;

	i = 0;
	size = strlen(s1);
	s2 = (char *)malloc((size * sizeof(char)) + 1);
	if (!s2)
		return (0);
	while (i < size)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	add_path_to_env(t_tools *tools)
{
	int	i;
	char	*tmp;

	i = 0;
	while (tools->envp[i])
	{
		if (ft_strncmp(tools->envp[i], "PWD=", 4) == 0)
		{
			tmp = ft_strjoin("PWD=", tools->pwd);
			free(tools->envp[i]);
			tools->envp[i] = tmp;
		}
		else if (ft_strncmp(tools->envp[i], "OLDPWD=", 7) == 0)
		{
			tmp = ft_strjoin("OLDPWD=", tools->pwd);
			free(tools->envp[i]);
			tools->envp[i] = tmp;
		}
		i++;
	}
}

char	*find_path_minicd(char *str, t_tools *tools)
{
	int	i;

	i = 0;
	while(tools->envp[i])
	{
		if (ft_strncmp(tools->envp[i], str, strlen(str)) == 0)
			return (ft_substr(tools->envp[i], strlen(str),
						strlen(tools->envp[i]) - strlen(str)));
		i++;
	}
	return (NULL);
}

int	goto_path(t_tools *tools, char *str)
{
	char	*tmp;
	int	res;

	tmp = find_path_minicd(str, tools);
	res = chdir(tmp);
	free(tmp);
	//error handling
}

void	change_path(t_tools *tools)
{
	char	*tmp;

	tmp = ft_strdup1(tools->pwd);
	free(tools->old_pwd);
	tools->old_pwd = tmp;
	free(tools->pwd);
	tools->pwd = getcwd(NULL, sizeof(NULL));
}

//must be implemented like the builtin in bash
//with only relative or absolut path
int	mini_cd(t_tools *tools, t_simple_cmds *simple_cmd)
{
	int		res;
	char	*new_pwd;

	if (!simple_cmd -> str[1])
		res = goto_path(tools, "HOME="); // if only cd is called, returns to home dir
	else if (ft_strncmp(simple_cmd->str[1], "-", 1) == 0)
	{
		res = goto_path(tools, "OLDPWD="); // if cd - is called, goes to oldpwd and prints oldpwd
		printf("\n%s\n", tools->old_pwd); //  if cd - is called in bash, and this is the first cd of the session, following is printed "bash: cd: OLDPWD not set"
	}
	else
	{
		res = chdir(simple_cmd->str[1]);
	}
	if (res != 0)
		return (EXIT_FAILURE);
	else
	{
		// Update PWD and OLDPWD
        free(tools->old_pwd); // Free old value to avoid memory leaks
        tools->old_pwd = tools->pwd; 
        new_pwd = getcwd(NULL, 0); // Get the new working directory
        if (!new_pwd) {
            perror("getcwd");
            return EXIT_FAILURE; 
        }
        tools->pwd = new_pwd;
	}
	// printf("res: %d\n", res);
//	change_path(tools);
//	add_path_to_env(tools);
	return(EXIT_SUCCESS);
}
