/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:53:46 by jjerde            #+#    #+#             */
/*   Updated: 2019/07/20 18:23:54 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_check_cp(char *s)
{
	int	i;
	int	allow;

	i = 0;
	allow = 0;
	while (s[i])
	{
		if ((s[i] >= '1' && s[i] <= '9') || s[i] == '.')
			allow = 1;
		else if (s[i] == '0' && allow == 0)
			return (0);
		else if (s[i] == 43 || s[i] == 39)
			return (0);
		else if (s[i] == 'c' || s[i] == 'p')
			return (1);
		++i;
	}
	return (0);
}

int	flag_check_s(char *str)
{
	int	i;
	int	allow;

	i = 0;
	allow = 0;
	while (str[i])
	{
		if (str[i] == '.' || (str[i] >= '1' && str[i] <= '9'))
			allow = 1;
		else if (str[i] == '0' && allow == 0)
			return (0);
		else if (str[i] == '+' || str[i] == '#' || str[i] == 32 || str[i] == 39)
			return (0);
		else if (str[i] == 's')
			return (1);
		++i;
	}
	return (0);
}

int	flag_check3(t_prms *p)
{
	int i;

	i = 0;
	if (p->c == 'i' || p->c == 'd' || p->c == 'D')
	{
		if (ft_strsearch(p->f, '#') >= 0)
			return (0);
		else
		{
			return (1);
		}
	}
	else if (p->c == 'c' || p->c == 'p')
		return (flag_check_cp(p->f));
	else if (p->c == 's')
		return (flag_check_s(p->f));
	return (0);
}

int	flag_check2(t_prms *p)
{
	int i;

	i = 0;
	if (p->c == 'o' || p->c == 'x' || p->c == 'X' || p->c == 'O')
	{
		while (p->f[i])
			if (p->f[i] == '+' || p->f[i] == ' ' || p->f[i++] == 39)
				return (0);
		return (1);
	}
	else if (p->c == 'u' || p->c == 'U')
	{
		while (p->f[i])
			if (p->f[i++] == '#')
				return (0);
		return (1);
	}
	return (flag_check3(p));
}

int	flag_check1(t_prms *p)
{
	int i;

	i = 0;
	if (p->c == 'f' || p->c == 'F' || p->c == 'g' || p->c == 'G' ||
			p->c == '%')
	{
		return (1);
	}
	else if (p->c == 'e' || p->c == 'E')
	{
		if (ft_strsearch(p->f, 39) >= 0)
			return (0);
		else
		{
			return (1);
		}
	}
	return (flag_check2(p));
}
