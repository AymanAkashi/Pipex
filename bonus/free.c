/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:07:52 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/04/20 15:41:44 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/pipex_bonus.h"

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

void 	free_table_int(t_data *data)
{
	int i;

	i = -1;
	while(data->end[++i])
		free(data->end[i]);
	free(data->end);
}

void free_pipe(t_data *data)
{
	while(data->pip)
	{
		free(data->pip->cmd);
		free(data->pip->cmd_path);
		free_array(data->pip->spl);
		data->pip = data->pip->next;
	}
}

void	free_all(t_data *data)
{
	free_array(data->path);
	free_array(data->path_spl);
	free_pipe(data);
	free_table_int(data);
}
