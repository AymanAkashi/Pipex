/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:46:02 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/03/26 19:43:14 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/pipex.h"

char	*get_thecmd(t_data data)
{
	char	*tmp;
	char	*arg;

	while (*data.path)
	{
		tmp = ft_strjoin(*data.path, "/");
		arg = ft_strjoin(tmp, data.spl[0]);
		if (access(arg, 0) == 0)
			return (arg);
		free(arg);
		data.path++;
	}
	ft_printf("Error command not found %s\n", data.spl[0]);
	return (NULL);
}

int	check_if_path(t_data *data)
{
	if (access(data->spl[0], X_OK) == 0)
		return (1);
	return (0);
}

void	child_process_exe(t_data *data, char *envp[], char **av)
{
	dup2(data->end[1], 1);
	close(data->end[0]);
	dup2(data->infile, 0);
	data->spl = ft_split(av[2], ' ');
	if (check_if_path(data))
		execve(data->spl[0], data->spl, envp);
	else
	{	
		data->cmd_arg = get_thecmd(*data);
		execve(data->cmd_arg, data->spl, envp);
		write(2, "command not found\n", 18);
		exit(1);
	}
	free_all(data);
	exit(1);
}

void	child2_process_exe(t_data *data, char *envp[], char **av)
{
	dup2(data->end[0], 0);
	close(data->end[1]);
	dup2(data->outfile, 1);
	data->spl = ft_split(av[3], ' ');
	if (check_if_path(data))
		execve(data->spl[0], data->spl, envp);
	else
	{	
		data->cmd_arg = get_thecmd(*data);
		execve(data->cmd_arg, data->spl, envp);
		write(2, "command not found\n", 18);
		exit(1);
	}
	data->cmd_arg = get_thecmd(*data);
	execve(data->cmd_arg, data->spl, envp);
	free_all(data);
	exit(1);
}
