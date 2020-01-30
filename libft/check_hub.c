/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:25:17 by jjerde            #+#    #+#             */
/*   Updated: 2019/07/20 18:23:49 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_priority(t_prms *p)
{
	int		i;
	int		z;

	i = 0;
	while (i < p->l)
	{
		if (p->f[i] == '+')
			ft_strreplchar(p->f, ' ', 'z');
		else if (p->f[i] == '-')
		{
			z = 0;
			while ((p->f[z] < '1' || p->f[i] > '9') && p->f[z] != '.')
			{
				if (p->f[z] == '0')
					p->f[z] = 'z';
				++z;
			}
		}
		i++;
	}
}

void	check_doubles(t_prms *p)
{
	int		i;
	int		zero;

	i = 0;
	zero = 1;
	while (i < p->l)
	{
		if ((p->f[i] < '0' || p->f[i] > '9') && p->f[i] != '*' &&
				p->f[i] != '.' && p->f[i] != 'h' && p->f[i] != 'l')
			ft_strreplchar(&p->f[i + 1], p->f[i], 'z');
		else if (p->f[i] == '*')
			zero = 0;
		else if (p->f[i] == '0')
		{
			if (zero > 0)
				zero -= 1;
			else
				p->f[i] = 'z';
		}
		else
			zero = 99;
		++i;
	}
	check_priority(p);
}

int		check_long(t_prms *p)
{
	if (ft_strsearch("cs", p->c) >= 0)
	{
		return (!(ft_strstr(p->f, "ll") || ft_strsearch(p->f, 'L') >= 0 ||
				ft_strsearch(p->f, 'h') >= 0));
	}
	if (ft_strsearch("p%", p->c) >= 0)
	{
		return (!(ft_strsearch(p->f, 'L') >= 0 || ft_strsearch(p->f, 'l') >= 0
			|| ft_strsearch(p->f, 'h') >= 0));
	}
	if (ft_strsearch("idouxX", p->c) >= 0)
		return (!(ft_strsearch(p->f, 'L') >= 0));
	if (ft_strsearch("fFeEgG", p->c) >= 0)
		return (!(ft_strsearch(p->f, 'h') >= 0 || ft_strstr(p->f, "ll")));
	return (1);
}

int		flag_checker(t_prms *p)
{
	int		i;

	i = 0;
	if (ft_strsearch("scpidouxXfFeEgGbrk%DOU", p->c) >= 0)
	{
		if (flag_check1(p))
		{
			check_doubles(p);
			return (check_long(p));
		}
	}
	return (0);
}
