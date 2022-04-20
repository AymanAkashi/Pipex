/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:02:22 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/04/20 15:51:37 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include"../include/pipex_bonus.h"

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

// void	in_file_not_found(t_data *data, char **av, char *envp[])
// {
// 	if (pipe(data->end) == -1)
// 		ft_exit_ps("pipe failed\n", 1);
// 	data->pid1 = 1;
// 	data->pid2 = fork();
// 	if (data->pid2 < 0)
// 		perror("Fork :");
// 	if (data->pid2 == 0)
// 		child2_process_exe(data, data->pip->next, envp);
// 	close(data->end[0]);
// 	close(data->end[1]);
// 	waitpid(data->pid1, NULL, 0);
// 	waitpid(data->pid2, NULL, 0);
// 	free_all(data);
// 	exit(1);
// }

// void	out_file_not_permission(t_data *data, char **av, char *envp[])
// {
// 	if (pipe(data->end) == -1)
// 		ft_exit_ps("pipe failed\n", 1);
// 	data->pid1 = fork();
// 	if (data->pid1 < 0)
// 		perror("Fork :");
// 	if (data->pid1 == 0)
// 		child_process_exe(data, envp);
// 	data->pid2 = 1;
// 	close(data->end[0]);
// 	close(data->end[1]);
// 	waitpid(data->pid1, NULL, 0);
// 	waitpid(data->pid2, NULL, 0);
// 	free_all(data);
// 	exit(1);
// }

void	open_file(t_data *data, char **av, char *envp[], int ac)
{
	(void)envp;
	if(data->here_doc)
		data->infile = open(".here_doc.tmp", O_RDONLY);
	else
		data->infile = open(av[1], O_RDONLY);
	data->outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (data->infile < 0)
	{
		perror(av[1]);
		// in_file_not_found(data, av, envp);
		exit(1);
	}
	if (data->outfile < 0)
	{
		perror(av[ac - 1]);
		// out_file_not_permission(data, av, envp);
		exit(1);
	}
}
int nbr_pipe(t_data data, int ac)
{
	int num_cmd;
		num_cmd = ac - 3 - data.here_doc;
	return (num_cmd);
}

t_pip	*pip_alloc(char **av, char *envp[], int ac,int here_doc)
{
	t_pip *pip;
	t_pip *head;
	int i;

	(void)envp;
	i = 2;
	pip = malloc(sizeof(t_pip));
	if(!pip)
		return (NULL);
	head = pip;
	if (here_doc)
		i++;
	while (i < ac - 1)
	{
		pip->cmd = ft_split(av[i],' ')[0];
		pip->spl = ft_split(av[i],' ');
		i++;
		if(i < ac - 1)
			{
				pip->next = malloc(sizeof(t_pip));
				if(!pip->next)
					return (NULL);
			}
			
		pip = pip->next;
	}
	return (head);
}

void	check_path(t_data *data)
{
	t_pip	*tmp;
	char	*c;
	int		i;

	tmp = data->pip;
	while (tmp)
	{
		i = 0;
		while (data->path[i])
		{
			c = ft_strjoin( data->path[i], tmp->cmd);
			if (access(c, 0) == 0)
			{
				tmp->cmd_path = ft_strdup(c);
				free(c);
				break;
			}
			free(c);
			i++;
		}
		if (tmp->cmd_path == NULL)
			perror(tmp->cmd);
		tmp = tmp->next;
	}
}

void	malloc_pip(t_data *data,int size)
{
	int i;

	i = -1;
	data->end = (int **)malloc(sizeof(int *) * (size + 1));
	if (!data->end)
		return ;
	while (++i < size)
	{
		data->end[i] = (int *)malloc(sizeof(int) * 2);
		if(!data->end[i])
			return ;
	}
	data->end[i] = NULL;
}

void	make_dup2(t_data *data)
{
	if(data->i == 0)
	{
		write(1,"heeey1\n", 7);
		dup2(data->infile, 0);
		dup2(data->end[data->i][1], 1);
	}
	else if(data->num_cmd - 1 == data->i)
	{
		write(1,"heeey3\n", 7);
		dup2(data->end[data->i - 1][0], 0);
		dup2(data->outfile, 1);
	}
	else	
	{
		write(1,"heeey2\n", 7);
		dup2(data->end[data->i - 1][0], 0);
		dup2(data->end[data->i][1], 1);
	}
}

void	close_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data->num_cmd))
	{	
		close(data->end[i][0]);
		close(data->end[i++][1]);
	}
}
t_pip *get_p(t_data *data, int num_cmd)
{
	t_pip *tmp;
	int i;

	i = -1;
	tmp = data->pip;
	while(++i < num_cmd)
		if(tmp->next)
			tmp = tmp->next;
	return (tmp);	
}

void	pipex(t_data *data, char *envp[])
{

	t_pip *head;

	head = data->pip;
	data->i = -1;
	while(++(data->i) < data->num_cmd)
	{
		data->pid1 = fork();
		if(data->pid1 < 0)
			perror("Fork :");
		if(data->pid1 == 0)
		{
			make_dup2(data);
			close_pipes(data);
			head = get_p(data, data->i);
			execve(head->cmd_path, head->spl, envp);
			write(2, "C2ammand not found\n", 20);
			free_all(data);
			exit(1);
		}
	}
	close_pipes(data);
	waitpid(-1, NULL, 0);
}

void	valid_here_doc(char **av)
{
	char *str;
	char *limite;
	int file;

	file = open(".here_doc.tmp", O_CREAT | O_RDWR | O_TRUNC, 0000644);
	limite = ft_strjoin(av[2],"\n");
	while (1)
	{
		write(1, "here_doc >", 10);
		str = get_next_line(0);
		if(!ft_strncmp(str, limite,ft_strlen(limite)))
			break ;
		write(file, str, ft_strlen(str));
		free(str);
	}
	free(limite);
}
void	creat_pipe(t_data *data)
{
	malloc_pip(data, data->num_cmd);
	data->i = -1;
	while(++(data->i) < data->num_cmd)
		if(pipe(data->end[data->i]) == -1)
			ft_exit_ps("pipe failed\n", 1);
}

void check_here_doc(t_data *data, char **av, int ac)
{
	(void)ac;
	data->here_doc = 0;
	if(ft_strncmp("here_doc", av[1], 8) == 0)
		{
			valid_here_doc(av);
			data->here_doc = 1;
		}
}

int	main(int ac, char **av, char *envp[])
{
	t_data	data;

	if (ac < 5)
		ft_exit_ps("Error argement\n", 1);
	check_here_doc(&data, av, ac);
	open_file(&data, av, envp, ac);
	data.ac = ac;
	data.num_cmd = nbr_pipe(data, ac);
	data.path = add_back_slash(envp, &data);
	data.pip = pip_alloc(av, envp, ac, data.here_doc);
	check_path(&data);
	creat_pipe(&data);
	pipex(&data,envp);
	free_all(&data);
	system("leaks pipex_bonus");
	return (0);
}