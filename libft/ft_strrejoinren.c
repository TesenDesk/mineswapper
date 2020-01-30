/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrejoinren.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 13:40:17 by jjerde            #+#    #+#             */
/*   Updated: 2019/07/20 18:27:07 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrejoinren(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	size_t	ii;
	char	*ss;

	if (!s1 || !s2)
		return (NULL);
	if (!(ss = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ss[i] = s1[i];
		i++;
	}
	ii = 0;
	while (s2[ii] && n > ii)
	{
		ss[i + ii] = s2[ii];
		ii++;
	}
	free((void *)s1);
	free((void *)s2);
	ss[i + ii] = '\0';
	return (ss);
}
