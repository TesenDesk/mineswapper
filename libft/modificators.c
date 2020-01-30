/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modificators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:02:49 by jjerde            #+#    #+#             */
/*   Updated: 2019/07/20 18:25:21 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_space(char *r)
{
	if (!r)
		return (" ");
	if ((r[0] >= '1' && r[0] <= '9') || (r[0] == '0' && !r[1]))
	{
		r = ft_strjoinre(" ", r);
	}
	else if (r[0] == '0' && r[1] && r[1] != '.')
		r[0] = ' ';
	return (r);
}

char	*re_gr2(char *r, char c)
{
	int		i;
	char	*re;

	if ((i = ft_strsearch(r, '.')) < 0)
	{
		if (c == 'g' || c == 'G')
			c -= 2;
		i = ft_strsearch(r, c);
		if (i >= 0)
		{
			re = ft_memalloc(ft_strlen(r) + 1);
			ft_strncpy(re, r, i);
			re[i] = '.';
			ft_strcpy(&re[i + 1], &r[i]);
			ft_memdel((void **)&r);
			r = re;
		}
		else
			return (ft_strrejoin(r, "."));
	}
	return (r);
}

char	*gr_x(char *r, char c)
{
	if (r[0] == '0')
	{
		if (r[1] == '0')
			r[1] = c;
		else
		{
			r[0] = c;
			r = ft_strjoinre("0", r);
		}
	}
	else
	{
		if (c == 'x')
			r = ft_strjoinre("0x", r);
		else
			r = ft_strjoinre("0X", r);
	}
	return (r);
}

char	*re_gr(char *r, char c)
{
	if (c == 'o')
	{
		if (r[0] != '0')
			return (ft_strjoinre("0", r));
		return (r);
	}
	if (c == 'x' || c == 'X')
		return (gr_x(r, c));
	if (c == 'f' || c == 'F')
	{
		if (ft_strsearch(r, '.') < 0)
			return (ft_strrejoin(r, "."));
	}
	if (c == 'g' || c == 'G' || c == 'e' || c == 'E')
		return (re_gr2(r, c));
	return (r);
}

char	*ft_zero(int i, char *str)
{
	int		g;
	char	*str1;

	g = ft_strlen(str);
	if (i <= g)
		return (str);
	i -= g;
	str1 = malloc(sizeof(char*) * (i + 1));
	g = 0;
	while (i--)
		str1[g++] = '0';
	str1[g] = '\0';
	if (str[0] == '-')
	{
		str[0] = '0';
		str1[0] = '-';
	}
	return (ft_strrejoinre(str1, str));
}
