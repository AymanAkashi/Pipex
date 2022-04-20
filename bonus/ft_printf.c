/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:01:41 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/03/29 13:36:13 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/pipex_bonus.h"

int	ft_checkprintf(char a, va_list *av)
{
	int	ret;

	ret = 0;
	if (a == 'c')
		ret += ft_putchar(va_arg(*av, int));
	if (a == 'd' || a == 'i')
		ret += ft_putnbr(va_arg(*av, int));
	if (a == 's')
		ret += ft_putstr(va_arg(*av, char *));
	if (a == 'p')
		ret += ft_point(va_arg(*av, unsigned long int));
	if (a == '%')
		ret += ft_putchar('%');
	if (a == 'u')
		ret += ft_putdeci(va_arg(*av, int));
	if (a == 'X')
		ret += ft_upperhexa(va_arg(*av, int));
	if (a == 'x')
		ret += ft_2lowerhexa(va_arg(*av, int));
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	av;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(av, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ret += ft_checkprintf(format[i], &av);
			i++;
		}
		else
			ret += ft_putchar(format[i++]);
	}
	return (ret);
}
