/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:31:29 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/04/12 17:35:02 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/pipex_bonus.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	if(!str)
		return 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
