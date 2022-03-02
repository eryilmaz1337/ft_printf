/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfharicifonksiyonlar.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:36:06 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/03/02 13:53:17 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*hexdesimalxx(size_t sayi, int anahtar, size_t uzunluk, char *kalan)
{
	uzunluk = uzun(sayi) + 1;
	kalan = malloc(uzunluk--);
	kalan[uzunluk--] = '\0';
	while (sayi >= 16)
	{
		if (anahtar == 0)
			kalan[uzunluk--] = sec(sayi % 16);
		else
			kalan[uzunluk--] = secb(sayi % 16);
		sayi = sayi / 16;
	}
	if (anahtar == 0)
		kalan[uzunluk] = sec(sayi % 16);
	else
		kalan[uzunluk] = secb(sayi % 16);
	return (kalan);
}

char	*hexdesimal(size_t sayi, size_t uzunluk, char *kalan)
{
	uzunluk = uzun(sayi) + 3;
	kalan = malloc(uzunluk--);
	kalan[0] = '0';
	kalan[1] = 'x';
	kalan[uzunluk--] = '\0';
	if (sayi == 0)
		kalan[uzunluk--] = sec(sayi % 16);
	while (sayi > 0)
	{
		kalan[uzunluk--] = sec(sayi % 16);
		sayi = sayi / 16;
	}
	return (kalan);
}

size_t	dogalsayilar(unsigned int n)
{
	char	*sayi;
	size_t	i;
	size_t	i1;

	i = onluuzun(n) + 1;
	i1 = i;
	sayi = malloc(i--);
	sayi[i] = '\0';
	if (n == 0)
		sayi[--i] = 48 + n % 10;
	while (n > 0)
	{
		sayi[--i] = 48 + n % 10;
		n = n / 10;
	}
	ft_putstr_fd(sayi, 1);
	free(sayi);
	return (i1 - 1);
}
