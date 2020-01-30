/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_f_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarry <sgarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:43:51 by sgarry            #+#    #+#             */
/*   Updated: 2019/07/20 18:24:21 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_flag_f_0(char *str, long double i, int a, int index)
{
	float	g;
	int		t;
	int		e;

	e = 0;
	g = 999999999999999999;
	if (i > g)
	{
		a = 0;
		while (i > 10 && ++e)
			i /= 10;
		while (e-- != -1)
		{
			t = i;
			i -= t;
			str[a++] = t + '0';
			i *= 10;
		}
		if (index != 0)
			str[a++] = '.';
		return (a);
	}
	return (0);
}

char			*ft_flag_f_1(int a, char *str, int flag)
{
	a = ft_strlen(str);
	if (str[0] == '0')
	{
		a = -1;
		while (str[++a] != '\0')
			str[a] = str[a + 1];
	}
	if (flag)
	{
		str[a + 1] = '\0';
		while (--a >= 0)
			str[a + 1] = str[a];
		str[0] = '-';
	}
	return (str);
}
