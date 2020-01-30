/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:17:07 by jjerde            #+#    #+#             */
/*   Updated: 2019/07/20 18:34:15 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_ac(t_prms *p, va_list factor)
{
	int		i;

	i = 0;
	while (i < p->l)
	{
		if (p->f[i] == '.')
		{
			if (p->f[i + 1] == '*')
			{
				if (p->f[i + 2] != '.')
					return (va_arg(factor, int));
				else
					va_arg(factor, int);
			}
			else
			{
				if (p->f[i + 2] != '.')
					return (ft_atoi(&p->f[i + 1]));
			}
		}
		++i;
	}
	if (ft_strsearch("fFgGeEoxX", p->c) >= 0)
		return (6);
	return (0);
}

int		get_wd(t_prms *p, va_list factor)
{
	int		i;
	int		atoi;

	i = -1;
	while (++i < p->l)
	{
		if ((p->f[i] >= '1' && p->f[i] <= '9') || p->f[i] == '*')
		{
			if (p->f[i] == '*' && (i <= 0 || p->f[i - 1] != '.'))
			{
				if (p->f[i + 1] < '1' || p->f[i + 1] > '9')
					return (va_arg(factor, int));
				else
					va_arg(factor, int);
			}
			else if (p->f[i] >= '1' && p->f[i] <= '9' && (i <= 0 ||
					p->f[i - 1] != '.'))
			{
				atoi = ft_atoi(&p->f[i]);
				if (p->f[i + int_len(atoi)] != '*')
					return (atoi);
			}
		}
	}
	return (0);
}

char	*ft_plus(char *r)
{
	if (!r)
		return ("+");
	if ((r[0] >= '1' && r[0] <= '9') || (r[0] == '0' && !r[1]))
	{
		r = ft_strjoinre("+", r);
	}
	else if (r[0] == '0' && r[1] && r[1] != '.')
		r[0] = '+';
	return (r);
}

char	*mod_apply(t_prms *p, char *r)
{
	int		i;

	if (p->zero)
		r = ft_zero(p->wd, r);
	if (p->dot)
	{
		if ((p->c == 'd' || p->c == 'i') && (p->space || p->plus))
			r = ft_zero(p->ac + 1, r);
		else if (p->c == 's' && (int)ft_strlen(r) > (i = p->ac))
			r[i] = '\0';
		else if (p->c == 'd' || p->c == 'i' || p->c == 'o' || p->c == 'u')
			r = ft_zero(p->ac, r);
	}
	if (p->space)
		r = ft_space(r);
	if (p->plus)
		r = ft_plus(r);
	if (p->box)
		r = re_gr(r, p->c);
	if (p->minus)
		r = ft_minus(p->wd, r);
	else if (!p->zero)
		r = ft_width(p->wd, r);
	return (r);
}

void	todo(t_prms *p, va_list factor)
{
	int i;
	int zero;

	if (ft_strsearch(p->f, '#') >= 0)
		p->box = 1;
	if (ft_strsearch(p->f, '-') >= 0)
		p->minus = 1;
	if (ft_strsearch(p->f, '+') >= 0)
		p->plus = 1;
	if (ft_strsearch(p->f, ' ') >= 0)
		p->space = 1;
	if (ft_strsearch(p->f, '.') >= 0)
		p->dot = 1;
	p->wd = get_wd(p, factor);
	p->ac = get_ac(p, factor);
	i = -1;
	zero = 1;
	while (zero && p->f[++i] != p->c)
	{
		if (p->f[i] == '0' && zero == 1)
			p->zero = 1;
		else if ((p->f[i] >= '1' && p->f[i] <= '9') || p->f[i] == '.' ||
				p->f[i] == '*')
			zero = 0;
	}
}
