/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:07:52 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/03/23 16:15:20 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/pipex.h"

void free_array(char **str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		free(str[i++]);
	free(str);
}

void	free_all(t_data *data)
{
	free_array(data->path);
	free_array(data->path_spl);
	// free_array(data->spl);
	free(data->cmd_arg);
}
