/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfharicifonksiyonlar.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:36:06 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/02/28 16:36:08 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
char sec(int gelenascii)
{
    char *sec1 = "0123456789abcdef";
    return(sec1[gelenascii]);
}
char SEC(int gelenascii)
{
    char *sec1 = "0123456789ABCDEF";
    return(sec1[gelenascii]);
}
size_t uzun(size_t bolum)
{
    size_t uz;

    uz = 0;
    while (bolum > 16)
    {
        bolum = bolum / 10;
        uz++;
    }
    return (uz);
    
}
size_t onluuzun(unsigned int bolum)
{
    size_t uz;

    uz = 0;
    while (bolum > 10)
    {
        bolum = bolum / 10;
        uz++;
    }
    return (uz);
    
}

char *hexdesimal(unsigned long sayi, int anahtar)
{
    size_t uzunluk;
    uzunluk = uzun(sayi);
    char *kalan;
    
    kalan = malloc(uzunluk);
    if(anahtar == 2)
    {
        kalan[0]='0';
        kalan[1]='x';
        anahtar = 0;
    }
    while (sayi > 16)
    {
        if(anahtar==0)
            kalan[uzunluk] = sec(sayi % 16);
        else
            kalan[uzunluk] = SEC(sayi % 16);
        sayi = sayi / 16;
        uzunluk--;
    }
    if(anahtar==0)
        kalan[uzunluk] = sec(sayi % 16);
    else
        kalan[uzunluk] = SEC(sayi % 16);
    return (kalan);
}

size_t dogalsayilar(unsigned int n)
{
    char *sayi;
    size_t i;
    size_t i1;

    if(n == 0)
    {
        ft_putchar_fd('0', 1);
        return(1);
    }
    i = onluuzun(n) + 1;
    i1 = i;
    sayi = malloc(i + 1);
    sayi[i] = '\0';
    while (n > 10)
    {
        sayi[--i] = 48 + n % 10;
        n = n / 10;
    }
    i--;
    sayi[i] = 48 + n % 10;
    ft_putstr_fd(sayi, 1);
    free(sayi);
    return (i1);
}