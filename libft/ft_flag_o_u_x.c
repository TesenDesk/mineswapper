/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_o_u_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarry <sgarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:37:05 by sgarry            #+#    #+#             */
/*   Updated: 2019/07/20 18:24:45 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_abcd(unsigned long long i, int g)
{
	char	*str;
	char	*str1;
	int		f;
	char	c;

	str = "abcdef";
	str1 = "ABCDEF";
	if (i % 16 < 10)
		c = i % 16 + '0';
	else
	{
		f = i % 16 - 10;
		if (g == 1)
			c = str[f];
		else
			c = str1[f];
	}
	return (c);
}

char	*ft_flag_x(unsigned long long i, int a, int f, int r)
{
	char	*str;
	int		g;

	g = 0;
	str = malloc(sizeof(char*) * 9);
	if (!r && !i)
	{
		str[0] = '\0';
		return (str);
	}
	if (f != 1 && f != 2)
		f = 8;
	else
		f = 16;
	while (i >= 16 && --f)
	{
		str[g++] = ft_abcd(i, a);
		i /= 16;
	}
	str[g++] = ft_abcd(i, a);
	str[g] = '\0';
	return (ft_sswap(str));
}

char	*ft_flag_o(unsigned long long i, int f)
{
	char	*str;
	int		g;

	g = 0;
	str = malloc(sizeof(char*) * 12);
	if (!f && !i)
	{
		str[0] = '\0';
		return (str);
	}
	while (i >= 8)
	{
		str[g++] = i % 8 + '0';
		i /= 8;
	}
	str[g] = i + '0';
	str[++g] = '\0';
	return (ft_sswap(str));
}

char	*ft_flag_u(unsigned long long i)
{
	char	*str;
	int		g;

	g = 0;
	str = malloc(sizeof(char*) * 11);
	while (i >= 10)
	{
		str[g++] = i % 10 + '0';
		i /= 10;
	}
	str[g++] = i % 10 + '0';
	str[g] = '\0';
	return (ft_sswap(str));
}
