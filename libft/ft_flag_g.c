/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarry <sgarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 21:08:43 by sgarry            #+#    #+#             */
/*   Updated: 2019/07/20 18:28:43 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_g_1(long double f)
{
	int i;

	i = 0;
	if (f == 0)
		return (1);
	if (f < 1)
	{
		while (f < 1)
		{
			i++;
			f *= 10;
		}
	}
	else if (f >= 10)
		while (f > 9)
		{
			f /= 10;
			++i;
		}
	return (i);
}

void	ft_flag_g_2(char *str, char *str1, int a, int flag)
{
	while (str[a] != '\0')
	{
		str[a] == '.' ? flag = a : 0;
		a++;
	}
	a--;
	while ((str[a] == '0' || str[a] == '.') && (flag))
		a--;
	str[++a] = '\0';
	a = 0;
	flag = 0;
	while (str1[a] != 'e' && str1[a] != 'E')
	{
		str1[a] == '.' ? flag = a : 0;
		a++;
	}
	a--;
	while ((str1[a] == '0' || str1[a] == '.') && (flag) && flag <= a)
		a--;
	while (str1[a + 1] == '0' || str1[a + 1] == '.')
	{
		flag = a;
		while (str1[++flag])
			str1[flag] = str1[flag + 1];
	}
}

char	*ft_flag_g_end(char *str, char *str1, int index, long double f)
{
	int flag;
	int a;
	int z;

	if (f < 0)
		f *= -1;
	flag = 0;
	a = 0;
	while (str[a])
		a++;
	while (str1[flag])
		flag++;
	z = 0;
	if (f < 10 && f > 1)
		z = 2;
	else if (f > 1)
		while (f >= 1)
		{
			f /= 10;
			++z;
		}
	if (flag < a || index < z)
		return (ft_flag_g_end_free(str1, str));
	else
		return (ft_flag_g_end_free(str, str1));
}

int		ft_flag_g_3(long double f, int i)
{
	if (f < 0)
		i = ft_flag_g_1(-f);
	else
		i = ft_flag_g_1(f);
	return (i);
}

char	*ft_flag_g(long double f, int index, int big)
{
	char	*str1;
	char	*str;
	int		a;
	int		flag;
	int		i;

	if (f == 0)
		return ("0");
	i = ft_flag_g_3(f, 0);
	if (index <= i)
		a = i + 1;
	else
		a = index;
	if (index <= 0)
		flag = 1;
	else
		flag = index;
	str1 = ft_flag_e(f, flag - 1, big);
	(!index) ? ++index : 0;
	if (f < 1)
		str = ft_flag_f(f, index + i - 1, big);
	else
		str = ft_flag_f(f, a - i - 1, big);
	ft_flag_g_2(str, str1, a, flag);
	return (ft_flag_g_end(str, str1, index, f));
}
