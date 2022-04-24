/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:59:30 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/04/24 18:29:35 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/pipex_bonus.h"

void	nbr_pipe(t_data *data, int ac)
{
	data->num_cmd = ac - 3 - data->here_doc - data->j;
}

t_pip	*pip_alloc(char **av, int ac, int here_doc)
{
	t_pip	*pip;
	t_pip	*head;
	int		i;

	i = 2;
	pip = malloc(sizeof(t_pip));
	if (!pip)
		return (NULL);
	head = pip;
	if (here_doc)
		i++;
	while (i < ac - 1)
	{
		pip->spl = ft_split(av[i], ' ');
		pip->cmd = str_space(av[i]);
		i++;
		if (i < ac - 1)
		{
			pip->next = malloc(sizeof(t_pip));
			if (!pip->next)
				return (NULL);
		}
		pip = pip->next;
	}
	return (head);
}

void	malloc_pip(t_data *data, int size)
{
	int	i;	

	i = -1;
	data->end = (int **)malloc(sizeof(int *) * (size + 1));
	if (!data->end)
		exit(1);
	while (++i < size)
	{
		data->end[i] = (int *)malloc(sizeof(int) * 2);
		if (!data->end[i])
			exit(1);
	}
	data->end[i] = NULL;
}

void	ft_dup2(t_data *data)
{
	if (data->i == 0)
	{
		dup2(data->infile, 0);
		dup2(data->end[data->i][1], 1);
	}
	else if (data->num_cmd - 1 == data->i)
	{
		dup2(data->end[data->i - 1][0], 0);
		dup2(data->outfile, 1);
	}
	else
	{
		dup2(data->end[data->i - 1][0], 0);
		dup2(data->end[data->i][1], 1);
	}
}
