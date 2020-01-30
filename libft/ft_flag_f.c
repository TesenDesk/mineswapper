/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarry <sgarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 20:15:37 by sgarry            #+#    #+#             */
/*   Updated: 2019/07/20 18:24:26 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_flag_f_2(long double i, int index, char *str, int a)
{
	int g;
	int f;

	while (index-- != 0)
	{
		i *= 10;
		g = i;
		i -= g;
		if (index == 0 && i * 10 >= 5)
		{
			g += 1;
			f = a - 1;
			if (g == 10)
				ft_str(str, f);
		}
		str[a++] = g % 10 + '0';
	}
	str[a] = '\0';
	return (str);
}

int				ft_flag_f_4(char *str, int a, int index, long double i)
{
	unsigned long long int	g;

	g = i;
	i -= g;
	if (index != 0)
		str[a++] = '.';
	while (g >= 10)
	{
		str[a++] = g % 10 + '0';
		g /= 10;
	}
	str[a++] = g % 10 + '0';
	str[a++] = '0';
	str[a] = '\0';
	ft_sswap(str);
	return (a);
}

char			*ft_flag_f_3(char *str, int index, long double i, int a)
{
	unsigned long long		g;
	int						f;

	if (!(a = ft_flag_f_0(str, i, a, index)))
	{
		a = ft_flag_f_4(str, a, index, i);
		g = i;
		i -= g;
	}
	else
		i /= i;
	if (index == 0 && i * 10 >= 5)
	{
		i *= 10;
		f = a - 1;
		if (i == 5)
			ft_i_5(str, f);
		else
			ft_str(str, f);
	}
	return (ft_flag_f_2(i, index, str, a));
}

char			*ft_flag_f(long double i, int index, int big)
{
	char	*str;
	int		a;
	int		flag;
	char	*p;

	if ((p = ft_proverka(i, big)))
		return (p);
	flag = 0;
	if (i < 0)
	{
		i *= -1;
		flag = 1;
	}
	a = 0;
	str = malloc(sizeof(char) * (lint_len(i) + index + 4));
	ft_flag_f_3(str, index, i, a);
	return (ft_flag_f_1(a, str, flag));
}
