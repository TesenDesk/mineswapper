/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarry <sgarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:54:52 by sgarry            #+#    #+#             */
/*   Updated: 2019/07/20 18:24:49 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_power(int nb, int power)
{
	int	result;
	int r;

	if (power < 0)
	{
		return (0);
	}
	else if (power == 0)
	{
		return (1);
	}
	else
	{
		power -= 1;
		r = ft_power(nb, power);
		result = nb * r;
		return (result);
	}
}

char	*ft_flag_p(void *srr, int ac)
{
	char				*str;
	int					g;
	unsigned long long	i;

	g = 0;
	i = (unsigned long long)srr;
	str = ft_strnew(sizeof(char*) * 16);
	while (i >= 16)
	{
		str[g++] = ft_abcd(i, 1);
		i /= 16;
	}
	str[g++] = ft_abcd(i, 1);
	g = ac;
	str = ft_sswap(str);
	str = ft_zero(ac, str);
	str = ft_strjoinre("0x", str);
	return (str);
}
