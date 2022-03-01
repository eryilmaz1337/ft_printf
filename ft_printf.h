/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:39:10 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/03/01 18:25:00 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

char	sec(int gelenascii);
char	SEC(int gelenascii);

int		ft_printf(const	char *str, ...);

size_t	uzun(size_t bolum);
size_t	onluuzun(unsigned int bolum);

char	*hexdesimal(unsigned long sayi, int anahtar, size_t uzunluk, char *kalan);

size_t	dogalsayilar(unsigned int n);
#endif
