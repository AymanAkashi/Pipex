/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:02:22 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/04/20 15:46:42 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include"../include/pipex.h"

int	counter(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	return (i);
}

void	in_file_not_found(t_data *data, char **av, char *envp[])
{
	if (pipe(data->end) == -1)
		ft_exit_ps("pipe failed\n", 1);
	data->pid1 = 1;
	data->pid2 = fork();
	if (data->pid2 < 0)
		perror("Fork :");
	if (data->pid2 == 0)
		child2_process_exe(data, envp, av);
	close(data->end[0]);
	close(data->end[1]);
	waitpid(data->pid1, NULL, 0);
	waitpid(data->pid2, NULL, 0);
	free_all(data);
	exit(1);
}

void	out_file_not_permission(t_data *data, char **av, char *envp[])
{
	if (pipe(data->end) == -1)
		ft_exit_ps("pipe failed\n", 1);
	data->pid1 = fork();
	if (data->pid1 < 0)
		perror("Fork :");
	if (data->pid1 == 0)
		child_process_exe(data, envp, av);
	data->pid2 = 1;
	close(data->end[0]);
	close(data->end[1]);
	waitpid(data->pid1, NULL, 0);
	waitpid(data->pid2, NULL, 0);
	free_all(data);
	exit(1);
}

void	open_file(t_data *data, char **av, char *envp[])
{
	data->infile = open(av[1], O_RDONLY);
	data->outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (data->infile < 0)
	{
		perror(av[1]);
		in_file_not_found(data, av, envp);
	}
	if (data->outfile < 0)
	{
		perror(av[4]);
		out_file_not_permission(data, av, envp);
	}
}

int	main(int ac, char **av, char *envp[])
{
	t_data	data;

	if (ac != 5)
		ft_exit_ps("Error argement\n", 1);
	data.path = add_back_slash(envp, &data);
	open_file(&data, av, envp);
	if (pipe(data.end) == -1)
		ft_exit_ps("pipe failed\n", 1);
	data.pid1 = fork();
	if (data.pid1 < 0)
		perror("Fork :");
	if (data.pid1 == 0)
		child_process_exe(&data, envp, av);
	data.pid2 = fork();
	if (data.pid2 < 0)
		perror("Fork :");
	if (data.pid2 == 0)
		child2_process_exe(&data, envp, av);
	close(data.end[0]);
	close(data.end[1]);
	waitpid(data.pid1, NULL, 0);
	waitpid(data.pid2, NULL, 0);
	free_all(&data);
	return (0);
}
