/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_target_icsf_.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:27:00 by jjerde            #+#    #+#             */
/*   Updated: 2019/07/20 18:25:33 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*redirect_int(t_prms *p, va_list factor)
{
	char		*r;
	long long	i;

	i = get_int(p, factor);
	if (p->dot && !p->ac && !i)
		r = ft_memalloc(1);
	else
		r = ft_flag_i(i, p->ac);
	return (r);
}

char	*redirect_float(t_prms *p, va_list factor)
{
	char	*r;

	r = ft_flag_f(get_double(p, factor), p->ac, 0);
	return (r);
}

char	*redirect_char(t_prms *p, va_list factor)
{
	char	*r;

	r = ft_memalloc(2);
	r[0] = va_arg(factor, int);
	r[1] = '\0';
	if (!r[0])
	{
		p->empty = 1;
		if (!p->minus)
			p->wd -= 1;
	}
	return (r);
}

char	*redirect_str(va_list factor)
{
	char	*rz;
	char	*r;

	rz = va_arg(factor, char *);
	if (!rz)
	{
		r = ft_memalloc(7);
		r = ft_strcpy(r, "(null)");
	}
	else
	{
		r = ft_memalloc(ft_strlen(rz) + 1);
		r = ft_strcpy(r, rz);
	}
	if (!r)
	{
		r = ft_memalloc(7);
		r = ft_strcpy(r, "(null)");
	}
	return (r);
}

char	*redirect_prc(void)
{
	char	*r;
	int		i;

	i = 0;
	r = ft_memalloc(2);
	r[0] = '%';
	return (r);
}
