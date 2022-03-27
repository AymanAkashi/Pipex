/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:32:17 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/03/24 13:05:20 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_point(unsigned long nb)
{
	static int	i;

	write (1, "0x", 2);
	i = 2;
	if (nb < 10)
		i += ft_putchar(nb + 48);
	if (nb >= 10 && nb < 16)
		i += ft_putchar(nb + 87);
	if (nb > 15)
	{
		i += ft_lowerhexa(nb / 16);
		i += ft_lowerhexa(nb % 16);
	}
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long int nb)
{
	int	i;

	i = 0;
	i += ft_checksize(nb);
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (i);
}

int	ft_checksize(long long n)
{
	int			i;
	long int	j;

	i = 0;
	j = n;
	if (j == 0)
		i++;
	if (j < 0)
	{
		i++;
		j *= -1;
	}
	while (j >= 2147483648)
			j--;
	while (j > 0)
	{
		j /= 10;
		i++;
	}
	return (i);
}
