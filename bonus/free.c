/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:07:52 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/04/24 15:15:18 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/pipex_bonus.h"

void	free_single_pip(t_pip *data)
{
	free(data->cmd);
	free((data)->cmd_path);
	free_array((data)->spl);
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_table_int(t_data **data)
{
	int	i;

	i = -1;
	while ((*data)->end[++i])
		free((*data)->end[i]);
	free((*data)->end);
}

void	free_pipe(t_data *data)
{
	t_pip	*tmp;
	t_pip	*tmp2;

	tmp = data->pip;
	while (data->pip)
	{
		tmp2 = data->pip;
		free(data->pip->cmd);
		free(data->pip->cmd_path);
		free_array(data->pip->spl);
		data->pip = data->pip->next;
		if (tmp2)
			free(tmp2);
	}
}

void	free_all(t_data *data)
{
	free_array(data->path);
	free_array(data->path_spl);
	if (data->pip && data->num_cmd > 0)
	{
		free_pipe(data);
		free_table_int(&data);
	}
	if (data->here_doc)
		unlink(".here_doc.tmp");
}
