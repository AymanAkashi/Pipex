/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:49:40 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/04/24 14:55:38 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/pipex_bonus.h"

void	check_file(char *str)
{
	if (access(str, R_OK) != 0)
		perror(str);
}

char	*check_pr(char *path, char *cmd, t_pip *pip)
{
	char	*c;

	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		else
		{
			perror(cmd);
			pip->is_program = 1;
			return (ft_strdup(cmd));
		}
	}
	c = ft_strjoin(path, cmd);
	if (access(c, 0) == 0)
		return (c);
	else
	{
		free(c);
		return (NULL);
	}
}

void	check_path(t_data *data)
{
	t_pip	*tmp;

	tmp = data->pip;
	while (tmp && tmp->cmd)
	{
		data->j = -1;
		while (data->path[++(data->j)])
		{
			tmp->cmd_path = check_pr(data->path[data->j], tmp->cmd, tmp);
			if (tmp->cmd_path)
				break ;
		}
		if (tmp->cmd_path == NULL)
			perror(tmp->cmd);
		tmp = tmp->next;
	}
}
