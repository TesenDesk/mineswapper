/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarry <sgarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:36:52 by sgarry            #+#    #+#             */
/*   Updated: 2019/07/20 18:26:25 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_sswap(char *str)
{
	char	i;
	int		f;
	int		g;

	f = 0;
	g = 0;
	while (str[f])
		f++;
	if (str[g] == '-')
		g++;
	while (g < --f)
	{
		i = str[g];
		str[g] = str[f];
		str[f] = i;
		g++;
	}
	return (str);
}
