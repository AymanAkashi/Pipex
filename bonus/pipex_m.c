/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:36:59 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/04/17 15:43:22 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/pipex_bonus.h"

int	check_if_path(t_data *data)
{
	if (access(data->spl[0], X_OK) == 0)
		return (1);
	return (0);
}

void	child_process(t_data *data, char *envp[], char **av)
{
	(void)av;
	dup2(data->infile, 0);
	close(data->end[0][0]);
	dup2(data->end[0][1], 1);
	execve(data->pip->cmd_path, data->pip->spl, envp);
	printf("\n%s cmd 1\n",data->pip->cmd);
	printf("arg1 %s\n",data->pip->spl[0]);
	write(2, "command not found\n", 18);
	exit(1);
	free_all(data);
	exit(1);
}

void	child2_process(t_data *data, char *envp[], char **av)
{
	(void)av;
	dup2(data->outfile, 1);
	close(data->end[0][1]);
	dup2(data->end[0][0], 0);
	data->pip = data->pip->next;
	execve(data->pip->cmd_path, data->pip->spl, envp);
	printf("\n%s cmd 2\n",data->pip->cmd);
	printf("arg2 %s\n",data->pip->spl[1]);
	write(2, "command not found\n", 18);
	exit(1);
	free_all(data);
	exit(1);
}

void	pipex_mandatory(t_data *data, char **av, char *envp[])
{
	
	if (pipe(data->end[0]) == -1)
		ft_exit_ps("pipe failed\n", 1);
	data->pid1 = fork();
	if (data->pid1 < 0)
		perror("Fork :");
	if (data->pid1 == 0)
	{
		printf("pid1");
		child_process(data, envp, av);
	}
	data->pid2 = fork();
	if (data->pid2 < 0)
		perror("Fork :");
	if (data->pid2 == 0)
	{
		printf("pid2");
		child2_process(data, envp, av);
	}
	close(data->end[0][0]);
	close(data->end[0][1]);
	unlink(".here_doc.tmp");
	waitpid(data->pid1, NULL, 0);
	waitpid(data->pid2, NULL, 0);
	free_all(data);
	exit(1);
}