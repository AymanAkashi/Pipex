/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:46:02 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/04/20 15:46:02 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/pipex_bonus.h"

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
		free(tmp);
		free(arg);
		data.path++;
	}
	ft_printf("Error command not found %s\n", data.spl[0]);
	return (NULL);
}

void	child_process_exe(t_data *data, char *envp[], int i)
{
	dup2(data->infile, 0);
	close(data->end[i][0]);
	dup2(data->end[i][1], 1);
	execve(data->pip->cmd_path, data->pip->spl, envp);
	write(2, "c1mmand not found\n", 18);
	exit(1);
	free_all(data);
}

void	child2_process_exe(t_data *data, char *envp[], int i)
{
	dup2(data->end[i][0], 0);
	close(data->end[i][1]);
	dup2(data->outfile, 1);
	data->pip = data->pip->next;
	execve(data->pip->cmd_path, data->pip->spl, envp);
	write(2, "C2mmand not found\n", 18);
	exit(1);
	free_all(data);
	exit(1);
}

void	child_process_all(t_data *data, char *envp[], int i)
{
	dup2(data->end[i - 1][0], 0);
	dup2(data->end[i][1], 1);
	// close(data->end[i][0]);
	// close(data->end[i][1]);
	data->pip = data->pip->next;
	execve(data->pip->cmd_path, data->pip->spl, envp);
	write(2, "CAmmand not found\n", 18);
	exit(1);
	free_all(data);
	exit(1);
}

void	child_process_all2(t_data *data, char *envp[])
{
	dup2(data->end[data->i][0], 0);
	close(data->end[data->i][1]);
	dup2(data->outfile, 1);
	execve(data->cmd_arg, data->spl, envp);
	write(2, "Command not found\n", 18);
	exit(1);
	free_all(data);
	exit(1);
}