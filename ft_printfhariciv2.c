/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhariciv2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:04:45 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/03/02 12:09:41 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	sec(int gelenascii)
{
	char	*sec1;

	sec1 = "0123456789abcdef";
	return (sec1[gelenascii]);
}

char	secb(int gelenascii)
{
	char	*sec1;

	sec1 = "0123456789ABCDEF";
	return (sec1[gelenascii]);
}

size_t	uzun(unsigned long bolum)
{
	size_t	uz;

	uz = 0;
	if (bolum == 0)
		return (1);
	while (bolum > 0)
	{
		bolum = bolum / 16;
		uz++;
	}
	return (uz);
}

size_t	onluuzun(unsigned int bolum)
{
	size_t	uz;

	uz = 0;
	if (bolum == 0)
		return (1);
	while (bolum > 0)
	{
		bolum = bolum / 10;
		uz++;
	}
	return (uz);
}
