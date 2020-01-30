/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarry <sgarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:54:11 by sgarry            #+#    #+#             */
/*   Updated: 2019/07/20 18:24:40 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag_i(long long int i, int index)
{
	char				*str;
	int					a;
	unsigned long long	n;
	int					len;

	if (i < 0)
		n = -i;
	else
		n = i;
	a = 0;
	len = lint_len(i);
	str = malloc(sizeof(char) * (len + index + 1));
	while (n >= 10)
	{
		str[a++] = n % 10 + '0';
		n /= 10;
	}
	str[a++] = n % 10 + '0';
	while (--index >= len)
		str[a++] = '0';
	if (i < 0)
		str[a++] = '-';
	str[a] = '\0';
	return (ft_sswap(str));
}
