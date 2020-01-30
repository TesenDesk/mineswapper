/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_e_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarry <sgarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:28:19 by sgarry            #+#    #+#             */
/*   Updated: 2019/07/20 18:24:06 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flag_e_1(char *str, int a, int f)
{
	if (str[a - 3] == '+')
	{
		while (str[++f] != '\0')
			str[f] = str[f + 1];
		if (str[f - 2] != '9')
			str[f - 2] = str[f - 2] + 1;
		else
		{
			str[f - 2] = '0';
			str[f - 3] = str[f - 3] + 1;
		}
	}
	else
	{
		while (str[++f] != '\0')
			str[f] = str[f + 1];
		if (str[f - 2] != '0')
			str[f - 2] = str[f - 2] - 1;
		else
		{
			str[f - 2] = '9';
			str[f - 3] = str[f - 3] - 1;
		}
		str[f - 2] == '0' && str[f - 3] == '0' ? str[f - 4] = '+' : 0;
	}
}

void		ft_flag_e_3(char *str, int flag, int a)
{
	if (flag == 8 || flag == 12 || flag == 3)
	{
		str[a + 1] = '\0';
		while (--a >= 0)
			str[a + 1] = str[a];
		str[0] = '-';
	}
}
