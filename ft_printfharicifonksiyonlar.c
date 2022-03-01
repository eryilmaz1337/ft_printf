/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfharicifonksiyonlar.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:36:06 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/03/01 19:30:49 by eryilmaz         ###   ########.tr       */
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

int	atama(char *kalan, size_t uzunluk)
{
	kalan[0] = '0';
	kalan[1] = 'x';
	kalan[uzunluk--] = '\0';
	return (uzunluk);
}

char	*hexdesimali(size_t  sayi, int anahtar, size_t uzunluk, char *kalan)
{
	if (anahtar == 2)
	{
		uzunluk = uzun(sayi) + 3;
		uzunluk = atama(kalan,uzunluk);
		anahtar = 0;
	}
	else
	{
		uzunluk = uzun(sayi) + 1;
		kalan[uzunluk--]='\0';
	}
	kalan = malloc(uzunluk--);
	while (sayi >= 16)
	{
		if (anahtar==0)
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

size_t	dogalsayilar(unsigned int n)
{
	char *sayi;
	size_t i;
	size_t i1;

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
