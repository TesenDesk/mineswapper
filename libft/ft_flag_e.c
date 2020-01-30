/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarry <sgarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:45:25 by sgarry            #+#    #+#             */
/*   Updated: 2019/07/20 18:24:10 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_e_2(char *str, int a, int e, int flag)
{
	str[a++] = 'e';
	if (flag == 6 || flag == 8 || flag == 1 || flag == 3)
		str[a++] = '+';
	else
		str[a++] = '-';
	if (e < 10)
	{
		str[a++] = '0';
		str[a++] = e + '0';
	}
	else
	{
		str[a + 1] = e % 10 + '0';
		e /= 10;
		str[a++] = e + '0';
		a++;
	}
	str[a] = '\0';
	if (str[0] == '0')
		ft_strcpy(str, &str[1]);
	else
		ft_flag_e_1(str, a, 0);
	ft_flag_e_3(str, flag, a);
	return (a);
}

int		ft_flag_e_4(char *str, int index, long double i, int a)
{
	int f;
	int g;

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
	return (a);
}

char	*ft_flag_e_0(long double i, int e, int flag, int index)
{
	char	*str;
	int		a;
	int		g;
	int		f;

	str = malloc(sizeof(char) * (index + 10));
	a = 0;
	str[a++] = '0';
	g = (int)i;
	i -= g;
	str[a++] = g + '0';
	if (index)
		str[a++] = '.';
	if (index == 0 && i * 10 >= 5)
	{
		i *= 10;
		f = a - 1;
		if (i == 5)
			ft_i_5(str, f);
		else
			ft_str(str, f);
	}
	a = ft_flag_e_4(str, index, i, a);
	ft_flag_e_2(str, a, e, flag);
	return (str);
}

char	*ft_flag_e_end(char *str, int big)
{
	int a;

	a = 0;
	if (big)
		while (str[a++] != '\0')
		{
			if (str[a] == 'e')
				str[a] = 'E';
		}
	return (str);
}

char	*ft_flag_e(long double i, int index, int big)
{
	int		e;
	int		flag;

	if (ft_proverka(i, big))
		return (ft_proverka(i, big));
	flag = 1;
	e = 0;
	if (i < 0 && (i *= -1))
		flag = 3;
	if (i >= 10)
	{
		while (i >= 10 && ++e)
			i /= 10;
		flag += 5;
	}
	if (i < 1 && i != 0)
	{
		while (i < 1 && ++e)
			i *= 10;
		flag += 9;
	}
	return (ft_flag_e_end(ft_flag_e_0(i, e, flag, index), big));
}
