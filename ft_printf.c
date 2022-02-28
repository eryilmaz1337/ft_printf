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

size_t yazdirma(va_list liste, char tip)
{
    size_t uz;
    char *a;
    int i;
    a = NULL;
    i = 0;
    uz = 0;
    if(tip == 'd' || tip == 'i' )
        a = ft_itoa(va_arg(liste, int));
    else if(tip == 'c')
    {
        ft_putchar_fd(va_arg(liste,int), 1);
        return(1);
    }
    else if(tip == 's')
    {
        
        a = va_arg(liste, char *);
        if(a == NULL)
        {
            ft_putstr_fd("(null)" , 1);
            return(6);
        }
        i = 1;
    }
    else if(tip == 'p')
        a = hexdesimal(va_arg(liste,unsigned long),2);
    else if(tip == 'u')
        return(dogalsayilar(va_arg(liste,unsigned int)));
    else if(tip == 'X')
        a = hexdesimal(va_arg(liste,unsigned int),1);
    else if(tip == 'x')
        a = hexdesimal(va_arg(liste,unsigned int),0);
    ft_putstr_fd(a, 1);
    uz = ft_strlen(a);
    if(i == 0)
        free(a);
    return (uz);
    
}
int ft_printf(const char *str, ...)
{
    va_list liste;
    size_t i;
    size_t gelen;

    i = 0;
    gelen = 0;
    va_start(liste,str);
    while (str[i])
    {
        if(str[i]=='%')
        {
            i++;
            gelen += yazdirma(liste,str[i]);
        }
        else
        {
            ft_putchar_fd(str[i],1);
            gelen++;
        }
        i++;
    }
    va_end(liste);
    return (gelen);
}
/*
int main()
{
    //char a[45] = "ahmet";
    //char *s = a;
     //printf("\n%d\n", printf("aa s%p%p",s, s+2));
    if(ft_printf("%d",12)==printf("%d",12))
        printf("\ndoğru");
   else
    {
          printf("\nHata!!!!!!!!!!!!!");
          printf("(%d)",ft_printf("%d", 12));
          printf("(%d)",printf("\n%d", 12));
    }
   //ft_printf("%d",12);
   printf("*%d*\n", ft_printf("%d\n",12));
   printf("*%d*", printf("%d\n",12));
}*/