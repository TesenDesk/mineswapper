/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_depleted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:14:55 by jjerde            #+#    #+#             */
/*   Updated: 2019/07/20 21:40:52 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_type(t_prms *p)
{
	int		i;

	i = -1;
	while (++i < p->l)
	{
		if (p->f[i] == 'l')
		{
			if (p->f[i + 1] == 'l')
				return (2);
			return (1);
		}
		else if (p->f[i] == 'L')
			return (3);
		else if (p->f[i] == 'h')
		{
			if (p->f[i + 1] == 'h')
				return (5);
			return (4);
		}
	}
	return (0);
}

void	fix2(t_prms *p)
{
	if (p->zero && p->ac < 0 && !p->minus)
		p->zero = 1;
	else if (p->zero && ((p->dot && (p->c != 'g' && p->c != 'G')) || p->minus))
		p->zero = 0;
	if (p->ac < 0)
	{
		if (ft_strsearch("fFgGeE", p->c) >= 0)
			p->ac = 6;
		else
		{
			p->ac = 0;
			p->dot = 0;
		}
	}
}

void	fix(t_prms *p)
{
	if (p->c == 'D' || p->c == 'O' || p->c == 'U')
		p->c += 32;
	if (p->c == 'c')
	{
		p->space = 0;
		p->ac = 0;
		p->box = 0;
	}
	else if (p->c == 'u')
	{
		p->space = 0;
		p->plus = 0;
	}
	if (p->wd < 0)
	{
		if (ft_strsearch("fFgGeE", p->c) >= 0)
			p->wd = 6;
		else
		{
			p->wd *= -1;
			p->minus = 1;
		}
	}
	fix2(p);
}

char	*pool(t_prms *p, va_list factor)
{
	char	*out;

	todo(p, factor);
	fix(p);
	p->type = get_type(p);
	if (p->c == 'd' || p->c == 'i')
		out = redirect_int(p, factor);
	else if (p->c == 'c')
		out = redirect_char(p, factor);
	else if (p->c == '%')
		out = redirect_prc();
	else if (p->c == 's')
		out = redirect_str(factor);
	else
		out = redirect_other(p, factor);
	if (p->c == 'o' && out[0] == '0' && !out[1])
		p->box = 0;
	else if (p->c == 'p' && p->dot && !p->ac && out[2] == '0' && !out[3])
		out[2] = '\0';
	else if (p->c == 'u' && p->dot && !p->ac && out[0] == '0' && !out[1])
		out[0] = '\0';
	return (out = mod_apply(p, out));
}

int		printf_one(t_prms *p, va_list factor)
{
	char	*str;
	int		m;

	m = 0;
	p->c = p->f[p->l - 1];
	if ((p->valid = flag_checker(p)))
	{
		str = pool(p, factor);
		m = ft_strlen(str);
		if (p->empty && !p->minus)
			m += 1;
		if (!m && p->c == 'c')
			m = 1;
		else if (p->empty && p->c == 'c' && p->minus)
		{
			write(1, "\0", 1);
			write(1, str, m - 1);
		}
		else
			write(1, str, m);
		free(p->f);
		free(str);
	}
	return (m);
}
