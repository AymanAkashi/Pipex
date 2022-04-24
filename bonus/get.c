/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:56:10 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/04/24 14:55:55 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/pipex_bonus.h"

t_pip	*get_p(t_data *data, int num_cmd)
{
	t_pip	*tmp;
	int		i;

	i = -1;
	tmp = data->pip;
	while (++i < num_cmd)
		if (tmp->next)
			tmp = tmp->next;
	return (tmp);
}

char	*get_str(char **envp, int i, char *path)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	path = malloc(sizeof(char) * ft_strlen(envp[i]));
	if (!path)
		return (0);
	while (envp[i][j] && envp[i][j] != '=')
		j++;
	j++;
	while (envp[i][j] != '\0')
		path[k++] = envp[i][j++];
	return (path);
}

char	*get_path(char *envp[])
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
		{
			path = get_str(envp, i, path);
			break ;
		}
		i++;
	}
	return (path);
}
