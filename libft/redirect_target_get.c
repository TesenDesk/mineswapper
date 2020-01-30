/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_target_get.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:32:32 by jjerde            #+#    #+#             */
/*   Updated: 2019/07/20 18:25:29 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			get_int(t_prms *p, va_list factor)
{
	long long int		i;

	i = 0;
	if (p->type == 0)
		i = (int)va_arg(factor, int);
	else if (p->type == 1)
		i = (long int)va_arg(factor, long);
	else if (p->type == 2)
		i = va_arg(factor, long long);
	else if (p->type == 4)
		i = (short int)va_arg(factor, int);
	else if (p->type == 5)
		i = (char)va_arg(factor, int);
	return (i);
}

unsigned long long	get_uint(t_prms *p, va_list factor)
{
	unsigned long long	u;

	u = 0;
	if (p->type == 0)
		u = (unsigned int)va_arg(factor, unsigned int);
	else if (p->type == 1)
		u = (unsigned long)va_arg(factor, unsigned long);
	else if (p->type == 2)
		u = va_arg(factor, unsigned long long);
	else if (p->type == 4)
		u = (unsigned short int)va_arg(factor, unsigned int);
	else if (p->type == 5)
		u = (unsigned char)va_arg(factor, unsigned int);
	return (u);
}

long double			get_double(t_prms *p, va_list factor)
{
	long double			f;

	f = 0.0;
	if (p->type == 0 || p->type == 1)
		f = (double)va_arg(factor, double);
	else if (p->type == 3)
		f = va_arg(factor, long double);
	return (f);
}

char				*redirect_x(t_prms *p, va_list factor)
{
	char				*r;
	long long			x;

	x = get_uint(p, factor);
	if (x == 0)
		p->box = 0;
	if (p->c == 'x')
		r = ft_flag_x(x, 1, p->type, p->ac);
	if (p->c == 'X')
		r = ft_flag_x(x, 0, p->type, p->ac);
	if (p->dot && (int)ft_strlen(r) < p->ac)
	{
		if (!p->box)
			r = ft_zero(p->ac, r);
		else
			r = ft_zero(p->ac + 2, r);
	}
	return (r);
}

char				*redirect_other(t_prms *p, va_list factor)
{
	if (p->c == 'f')
		return (ft_flag_f(get_double(p, factor), p->ac, 0));
	if (p->c == 'F')
		return (ft_flag_f(get_double(p, factor), p->ac, 1));
	if (p->c == 'o')
		return (ft_flag_o(get_uint(p, factor), p->ac));
	if (p->c == 'x' || p->c == 'X')
		return (redirect_x(p, factor));
	if (p->c == 'g')
		return (ft_flag_g(get_double(p, factor), p->ac, 0));
	if (p->c == 'G')
		return (ft_flag_g(get_double(p, factor), p->ac, 1));
	if (p->c == 'e')
		return (ft_flag_e(get_double(p, factor), p->ac, 0));
	if (p->c == 'E')
		return (ft_flag_e(get_double(p, factor), p->ac, 1));
	if (p->c == 'p')
		return (ft_flag_p(va_arg(factor, void*), p->ac));
	if (p->c == 'u')
		return (ft_flag_u(get_uint(p, factor)));
	return ("Beep");
}
