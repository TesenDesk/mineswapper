/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:49:28 by jjerde            #+#    #+#             */
/*   Updated: 2019/07/20 18:24:02 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*flag_ending(t_flags *f, int t)
{
	char	*out;

	out = NULL;
	if (t)
	{
		if (t > 1)
			out = f->out;
		else
			free(f->out);
	}
	free(f);
	return (out);
}

char		*ft_flag_continue3(char *str, int i, int ii, t_flags *f)
{
	f->count = 0;
	while (ft_strsearch("hl", str[i]) >= 0 && f->count < 2)
	{
		if (f->count == 1 && f->out[ii - 1] != str[i])
			return (flag_ending(f, 1));
		f->out[ii++] = str[i++];
		f->end -= 1;
		f->count += 1;
	}
	if (str[i] == 'L' && f->count == 0)
	{
		f->out[ii++] = str[i++];
		f->end -= 1;
	}
	if (f->end == 1)
	{
		f->out[ii] = str[i];
		return (flag_ending(f, 2));
	}
	return (flag_ending(f, 1));
}

char		*ft_flag_continue2(char *str, int i, int ii, t_flags *f)
{
	f->count = 0;
	while (str[i] == '.')
	{
		f->out[ii++] = str[i++];
		f->end -= 1;
		f->count = 1;
		while ((str[i] >= '0' && str[i] <= '9' && f->count < 3) ||
				(str[i] == '*' && f->count < 2))
		{
			if (str[i] == '*')
				f->count = 1;
			else
				f->count = 1;
			f->out[ii++] = str[i++];
			f->end -= 1;
		}
	}
	return (ft_flag_continue3(str, i, ii, f));
}

char		*ft_flag_continue(char *str, int i, int ii, t_flags *f)
{
	while ((str[i] >= '0' && str[i] <= '9' && f->count < 3) ||
			(str[i] == '*' && f->count < 2))
	{
		f->out[ii++] = str[i++];
		f->end -= 1;
	}
	return (ft_flag_continue2(str, i, ii, f));
}

char		*ft_flags_start(char *str)
{
	t_flags	*f;
	int		i;
	int		ii;

	f = (t_flags *)ft_memalloc(sizeof(t_flags));
	i = 0;
	f->end = 1;
	while (str[i + f->end] && ft_strsearch("cspidouxXfFeEgGbrk%UOD",
			str[i + f->end]) < 0)
		f->end += 1;
	if (f->end < 0)
		return (flag_ending(f, 0));
	f->out = ft_strnew(f->end);
	ii = 0;
	i += 1;
	f->count = 0;
	while (ft_strsearch("0+- #", str[i]) >= 0)
	{
		f->out[ii++] = str[i++];
		f->end -= 1;
		f->count = 1;
	}
	return (ft_flag_continue(str, i, ii, f));
}
