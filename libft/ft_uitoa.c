/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:41:51 by jjerde            #+#    #+#             */
/*   Updated: 2019/07/20 18:27:27 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			uint_len(unsigned long long c)
{
	int		i;

	i = 1;
	while (c > 9)
	{
		i++;
		c = c / 10;
	}
	return (i);
}

char		*ft_uitoa(unsigned long long n)
{
	char				*str;
	int					len;
	unsigned long long	bck;

	bck = n;
	len = uint_len(n);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = 0 + '0';
	while (bck > 0)
	{
		str[--len] = bck % 10 + '0';
		bck = bck / 10;
	}
	return (str);
}
