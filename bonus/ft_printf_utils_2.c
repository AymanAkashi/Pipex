/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:21:14 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/03/29 13:36:19 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/pipex_bonus.h"

int	ft_putdeci(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb < 10)
		i += ft_putchar(nb + 48);
	if (nb >= 10)
	{
		i += ft_putdeci(nb / 10);
		i += ft_putdeci(nb % 10);
	}
	return (i);
}

int	ft_upperhexa(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb < 10)
		i += ft_putchar(nb + 48);
	if (nb > 9 && nb < 16)
		i += ft_putchar(nb + 55);
	if (nb > 15)
	{
		i += ft_upperhexa(nb / 16);
		i += ft_upperhexa(nb % 16);
	}
	return (i);
}

int	ft_2lowerhexa(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb < 10)
		i += ft_putchar(nb + 48);
	if (nb > 9 && nb < 16)
		i += ft_putchar(nb + 87);
	if (nb > 15)
	{
		i += ft_lowerhexa(nb / 16);
		i += ft_lowerhexa(nb % 16);
	}
	return (i);
}

int	ft_lowerhexa(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb < 10)
		i += ft_putchar(nb + 48);
	if (nb > 9 && nb < 16)
		i += ft_putchar(nb + 87);
	if (nb > 15)
	{
		i += ft_lowerhexa(nb / 16);
		i += ft_lowerhexa(nb % 16);
	}
	return (i);
}
