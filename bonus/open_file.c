/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:18:05 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/04/24 14:58:36 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

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

void	open_file(t_data *data, char **av, int ac)
{
	data->i = -1;
	data->j = 0;
	if (data->here_doc)
	{
		data->infile = open(".here_doc.tmp", O_RDONLY);
		data->outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0000644);
	}
	else
	{	
		data->infile = open(av[1], O_RDONLY);
		data->outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0000644);
	}
	if (data->infile < 0)
	{
		perror(av[1]);
		data->i++;
	}
	if (data->outfile < 0)
	{
		perror(av[ac - 1]);
		data->j = 1;
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
