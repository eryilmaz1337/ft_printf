/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:38:42 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/02/24 13:38:43 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
char sec(int gelenascii)
{
    char *sec1 = "0123456789abcdef";
    return(sec1[gelenascii]);
}
char *hexdesimal(unsigned long sayi, int giriskodu, int bitis, size_t uzunluk)
{
    char *kalan;
    unsigned long bolum;
    bolum = sayi;
    while (bolum > 16)
    {
        if(giriskodu == 1)
        {
            if(bolum > 16)
            {
                kalan[uzunluk--] = sec(bolum % 16);
                bitis = 1;
            }   
            bolum = bolum / 16;
        }
        if(giriskodu == 0)
        {   
            bolum = bolum / 16;
            uzunluk++;
        }
        if(bolum < 16 && bitis == 0)
        {
            kalan = malloc(uzunluk + 3);
            giriskodu = 1;
            kalan[0] = '0';
            kalan[1] = 'x';
            uzunluk = uzunluk + 3;
            kalan[uzunluk--] = '\0';
            bolum = sayi;
        }
    }
    kalan[uzunluk] = sec(bolum % 16);
    return(kalan);
}
int yazdirma(va_list liste, char tip)
{
    int a;
    unsigned char a1;
    char *str;

    if(tip == 'd' || tip == 'i' )
        ft_putstr_fd(ft_itoa(va_arg(liste, int)), 1);
    else if(tip == 'c')
        ft_putchar_fd(va_arg(liste, int), 1);
    else if(tip == 's')
        ft_putstr_fd(va_arg(liste, char *), 1);
    else if(tip == 'p')
        ft_putstr_fd(hexdesimal(va_arg(liste,unsigned long), 0, 0, 0),1);

    return(0);
}
int ft_printf(const char *str, ...)
{
    va_list liste;
    size_t i;
    int gelen;

    i = 0;
    gelen = 0;
    va_start(liste,str);
    while (str[i])
    {
        if(str[i]=='%')
        {
            i++;
            gelen = yazdirma(liste,str[i]);
        }
        i++;
    }
    va_end(liste);
    return(0);
}
int main()
{
    char a[45] = "ahmet";
    char *s = a;
   // printf("\n%d\n", printf("aa s%p%p",s, s+2));
   ft_printf("%p", s);
   printf("\n%p", s);
}