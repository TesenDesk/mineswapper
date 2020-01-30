/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proverka.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarry <sgarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:21:05 by sgarry            #+#    #+#             */
/*   Updated: 2019/07/20 18:25:03 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_inf(int t)
{
	char	*r;

	if (t >= 0)
		r = ft_strnew(sizeof(char) * 4);
	else
		r = ft_strnew(sizeof(char) * 5);
	if (!t)
		ft_strcpy(r, "nan");
	else if (t == 1)
		ft_strcpy(r, "NAN");
	else if (t == 2)
		ft_strcpy(r, "inf");
	else if (t == 3)
		ft_strcpy(r, "INF");
	else if (t == -2)
		ft_strcpy(r, "-inf");
	else if (t == -3)
		ft_strcpy(r, "-INF");
	return (r);
}

static char			*ft_proverka_2(long double i, int big)
{
	if (i < 0)
		return (NULL);
	else if (i == 0)
		return (NULL);
	else if (i > 0)
		return (NULL);
	else if (big == 1)
		return (ft_inf(1));
	else
		return (ft_inf(0));
	return (NULL);
}

char				*ft_proverka(long double i, int big)
{
	float	proverka;

	proverka = 999999999999999999;
	proverka *= 1000000000000000000;
	proverka *= 100000000;
	if (i == proverka)
	{
		if (big == 1)
			return (ft_inf(3));
		else
			return (ft_inf(2));
	}
	if (i == -proverka)
	{
		if (big == 1)
			return (ft_inf(-3));
		else
			return (ft_inf(-2));
	}
	return (ft_proverka_2(i, big));
}
