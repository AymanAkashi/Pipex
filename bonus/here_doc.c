/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:09:04 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/04/23 23:23:42 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	valid_here_doc(char **av)
{
	char	*str;
	char	*limite;
	int		file;

	file = open(".here_doc.tmp", O_CREAT | O_RDWR | O_TRUNC, 0000644);
	limite = ft_strjoin(av[2], "\n");
	while (1)
	{
		write(1, "here_doc >", 10);
		str = get_next_line(0);
		if (!ft_strncmp(str, limite, ft_strlen(limite) + 1))
		{
			free(str);
			free(limite);
			break ;
		}
		write(file, str, ft_strlen(str));
		free(str);
	}
	close(file);
}

void	check_here_doc(t_data *data, char **av)
{
	data->here_doc = 0;
	if (ft_strncmp("here_doc", av[1], 9) == 0)
	{
		valid_here_doc(av);
		data->here_doc = 1;
	}
}
