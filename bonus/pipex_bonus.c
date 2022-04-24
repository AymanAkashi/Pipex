/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:02:22 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/04/24 18:09:49 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include"../include/pipex_bonus.h"

void	pipex(t_data *data, char *envp[])
{
	t_pip	*head;

	while (++(data->i) < data->num_cmd)
	{
		data->pid1 = fork();
		if (data->pid1 < 0)
			perror("Fork :");
		if (data->pid1 == 0)
		{
			ft_dup2(data);
			close_pipes(data);
			head = get_p(data, data->i);
			execve(head->cmd_path, head->spl, envp);
			write(2, "Cammand not found\n", 19);
			free_all(data);
			exit(1);
		}
	}
	close_pipes(data);
	data->i = -1;
	while (++(data->i) < data->num_cmd)
		waitpid(-1, NULL, 0);
}

void	creat_pipe(t_data *data)
{
	malloc_pip(data, data->num_cmd);
	data->j = -1;
	while (++(data->j) < data->num_cmd)
		if (pipe(data->end[data->j]) == -1)
			ft_exit_ps("pipe failed\n", 1);
}

int	main(int ac, char **av, char *envp[])
{
	t_data	data;

	if (ac < 5)
		ft_exit_ps("Error argement\n", 1);
	check_here_doc(&data, av);
	open_file(&data, av, ac);
	data.ac = ac;
	nbr_pipe(&data, ac);
	data.path = add_back_slash(envp, &data);
	data.pip = pip_alloc(av, ac, data.here_doc);
	check_path(&data);
	creat_pipe(&data);
	pipex(&data, envp);
	free_all(&data);
	return (0);
}
