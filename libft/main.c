/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:23:07 by jjerde            #+#    #+#             */
/*   Updated: 2019/09/28 20:53:34 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prms	*p_inicialise(void)
{
	t_prms	*p;

	if (!(p = (t_prms *)ft_memalloc(sizeof(t_prms))))
		return (NULL);
	p->valid = 1;
	p->type = -1;
	return (p);
}

void	p_reset(t_prms *p)
{
	p->c = 0;
	p->l = 0;
	p->f = NULL;
	p->wd = 0;
	p->ac = 0;
	p->zero = 0;
	p->space = 0;
	p->box = 0;
	p->plus = 0;
	p->minus = 0;
	p->dot = 0;
	p->valid = 1;
	p->type = -1;
	p->empty = 0;
}

t_prms	*push_to(t_prms *p, char *k)
{
	if (!p)
		p = p_inicialise();
	else
		p_reset(p);
	p->f = k;
	p->l = ft_strlen(p->f);
	return (p);
}

int		spinner(char *str, va_list factor, t_prms *p, int i)
{
	int		counter;
	char	*k;

	counter = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i++]);
			++counter;
		}
		else if ((k = ft_flags_start(&str[i])))
		{
			p = push_to(p, k);
			counter += printf_one(p, factor);
			if (p->valid)
				i += p->l + 1;
			else
				++i;
		}
		else
			++i;
	}
	free(p);
	return (counter);
}

int		ft_printf(const char *str, ...)
{
	va_list	factor;
	int		counter;
	t_prms	*p;
	int		i;
	char	*copy;

	if (!str)
		return (-1);
	p = NULL;
	i = 0;
	va_start(factor, str);
	copy = ft_memalloc(ft_strlen(str) + 1);
	ft_strcpy(copy, str);
	copy = colors_apply(copy);
	counter = spinner(copy, factor, p, i);
	va_end(factor);
	free(copy);
	return (counter);
}
