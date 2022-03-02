/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:38:42 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/03/02 13:52:44 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	yazdirmadevam(va_list liste, char tip)
{
	size_t	uz;
	char	*a;

	a = NULL;
	uz = 0;
	if (tip == 'p')
		a = hexdesimal(va_arg(liste, unsigned long), 0, NULL);
	else if (tip == 'u')
		return (dogalsayilar(va_arg(liste, unsigned int)));
	else if (tip == 'X')
		a = hexdesimalxx(va_arg(liste, unsigned int), 1, 0, NULL);
	else if (tip == 'x')
		a = hexdesimalxx(va_arg(liste, unsigned int), 0, 0, NULL);
	else if (tip == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	ft_putstr_fd(a, 1);
	uz = ft_strlen(a);
	free(a);
	return (uz);
}

size_t	yazdirma(va_list liste, char tip, int i, char *a)
{
	if (tip == 'd' || tip == 'i' )
		a = ft_itoa(va_arg(liste, int));
	else if (tip == 'c')
	{
		ft_putchar_fd(va_arg(liste, int), 1);
		return (1);
	}
	else if (tip == 's')
	{
		a = va_arg(liste, char *);
		if (a == NULL)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		i = 1;
	}
	else if (tip != 'd' && tip != 'i' && tip != 'c' && tip != 's')
		return (yazdirmadevam(liste, tip));
	ft_putstr_fd(a, 1);
	if (i == 0)
		free(a);
	return (ft_strlen(a));
}

int	ft_printf(const char *str, ...)
{
	va_list	liste;
	size_t	i;
	size_t	gelen;

	i = 0;
	gelen = 0;
	va_start(liste, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			gelen += yazdirma(liste, str[i], 0, NULL);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			gelen++;
		}
		i++;
	}
	va_end(liste);
	return (gelen);
}
