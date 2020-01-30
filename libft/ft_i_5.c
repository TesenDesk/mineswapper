/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarry <sgarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:26:45 by sgarry            #+#    #+#             */
/*   Updated: 2019/07/20 18:24:54 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_str(char *str, int f)
{
	while (1)
	{
		if (str[f] == '9')
			str[f--] = '0';
		else if (str[f] == '.')
			f--;
		else
		{
			str[f] = str[f] + 1;
			break ;
		}
	}
	return (str);
}

char		*ft_i_5(char *s, int f)
{
	if (s[f] == '0' || s[f] == '2' || s[f] == '4' || s[f] == '6' || s[f] == '8')
		return (NULL);
	return (ft_str(s, f));
}
