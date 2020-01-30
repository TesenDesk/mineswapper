/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:44:05 by jjerde            #+#    #+#             */
/*   Updated: 2019/07/20 18:26:40 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoinre(char const *s1, char const *s2)
{
	int		i;
	int		ii;
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
	while (s2[ii])
	{
		ss[i + ii] = s2[ii];
		ii++;
	}
	ft_memdel((void **)&s2);
	ss[i + ii] = '\0';
	return (ss);
}
