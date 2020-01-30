/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:43:17 by sgarry            #+#    #+#             */
/*   Updated: 2019/05/14 17:44:23 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int ss1, int ss2)
{
	char *str;

	if (s1 == NULL)
		s1 = ft_strnew(0);
	if (s2 == NULL)
		s2 = ft_strnew(0);
	str = ft_strjoin(s1, s2);
	if (ss1)
		free(s1);
	if (ss2)
		free(s2);
	return (str);
}
