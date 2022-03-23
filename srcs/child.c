/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:46:02 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/03/23 16:14:08 by aaggoujj         ###   ########.fr       */
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
	return (NULL);
}

void	child_process_exe(t_data *data, char *envp[], char **av)
{
	dup2(data->end[1], 1);
	close(data->end[0]);
	dup2(data->infile, 0);
	data->spl = ft_split(av[2], ' ');
	data->cmd_arg = get_thecmd(*data);
	execve(data->cmd_arg, data->spl, envp);
	free_all(data);
	printf("Error\n");
	exit(1);
}

void	child2_process_exe(t_data *data, char *envp[], char **av)
{
	dup2(data->end[0], 0);
	close(data->end[1]);
	dup2(data->outfile, 1);
	data->spl = ft_split(av[3], ' ');
	data->cmd_arg = get_thecmd(*data);
	execve(data->cmd_arg, data->spl, envp);
	free_all(data);
	printf("Error\n");
	exit(1);
}
