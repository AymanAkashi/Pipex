/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:56:10 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/03/23 16:10:42 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/pipex.h"

char	*str_space(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != ' ')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**add_back_slash(char *envp[], t_data *data)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	data->ft_path = get_path(envp);
	data->path_spl = ft_split(data->ft_path, ':');
	free(data->ft_path);
	str = (char **)malloc(sizeof(char *) * (counter(data->path_spl) + 1));
	while (data->path_spl[i])
	{
		j = -1;
		str[i] = (char *)malloc(sizeof(char)
				* (ft_strlen(data->path_spl[i]) + 2));
		while (data->path_spl[i][++j])
			str[i][j] = data->path_spl[i][j];
		str[i][j] = '/';
		str[i][j + 1] = '\0';
		i++;
	}
	str[i] = NULL;
	return (str);
}
