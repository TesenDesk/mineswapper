/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarry <sgarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 18:01:17 by sgarry            #+#    #+#             */
/*   Updated: 2019/07/20 18:25:08 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width(int i, char *str)
{
	int		g;
	char	*str1;

	g = ft_strlen(str);
	if (i <= g)
		return (str);
	i -= g;
	str1 = malloc(sizeof(char*) * (i + 1));
	g = 0;
	while (i--)
		str1[g++] = ' ';
	str1[g] = '\0';
	return (ft_strrejoinre(str1, str));
}
