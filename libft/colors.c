/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:53:01 by jjerde            #+#    #+#             */
/*   Updated: 2019/07/20 18:23:58 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strreplace(char *str, const char *old, const char *new)
{
	char	*res;
	size_t	n;
	char	*found;

	if (!(str && old && new))
		return (NULL);
	while ((found = ft_strstr(str, old)))
	{
		n = ft_strlen(old);
		res = ft_memalloc(ft_strlen(str) - n + ft_strlen(new) + 1);
		if (!res)
			return (NULL);
		ft_strncpy(res, str, found - str);
		ft_strcat(res, new);
		ft_strcat(res, found + n);
		free(str);
		str = res;
		res = NULL;
	}
	return (str);
}

char	*colors_other(char *str)
{
	if (ft_strstr(str, "{r}"))
		str = ft_strreplace(str, "{r}", "\033[0m");
	else if (ft_strstr(str, "{b}"))
		str = ft_strreplace(str, "{b}", "\033[1m");
	else if (ft_strstr(str, "{d}"))
		str = ft_strreplace(str, "{d}", "\033[2m");
	else if (ft_strstr(str, "{i}"))
		str = ft_strreplace(str, "{i}", "\033[3m");
	else if (ft_strstr(str, "{l}"))
		str = ft_strreplace(str, "{l}", "\033[4m");
	else if (ft_strstr(str, "{k}"))
		str = ft_strreplace(str, "{k}", "\033[5m");
	else if (ft_strstr(str, "{v}"))
		str = ft_strreplace(str, "{v}", "\033[7m");
	else if (ft_strstr(str, "{nb}"))
		str = ft_strreplace(str, "{nb}", "\033[22m");
	else if (ft_strstr(str, "{ni}"))
		str = ft_strreplace(str, "{ni}", "\033[23m");
	else if (ft_strstr(str, "{nl}"))
		str = ft_strreplace(str, "{nl}", "\033[24m");
	else if (ft_strstr(str, "{nk}"))
		str = ft_strreplace(str, "{nk}", "\033[25m");
	else if (ft_strstr(str, "{nv}"))
		str = ft_strreplace(str, "{nv}", "\033[27m");
	return (str);
}

char	*colors_background(char *str)
{
	if (ft_strstr(str, "{bblack}"))
		str = ft_strreplace(str, "{bblack}", "\033[40m");
	else if (ft_strstr(str, "{bred}"))
		str = ft_strreplace(str, "{bred}", "\033[41m");
	else if (ft_strstr(str, "{bgreen}"))
		str = ft_strreplace(str, "{bgreen}", "\033[42m");
	else if (ft_strstr(str, "{byellow}"))
		str = ft_strreplace(str, "{byellow}", "\033[43m");
	else if (ft_strstr(str, "{bblue}"))
		str = ft_strreplace(str, "{bblue}", "\033[44m");
	else if (ft_strstr(str, "{bmagenta}"))
		str = ft_strreplace(str, "{bmagenta}", "\033[45m");
	else if (ft_strstr(str, "{bcyan}"))
		str = ft_strreplace(str, "{bcyan}", "\033[46m");
	else if (ft_strstr(str, "{bgray}"))
		str = ft_strreplace(str, "{bgray}", "\033[47m");
	else
		str = colors_other(str);
	return (str);
}

char	*colors_text(char *str)
{
	if (ft_strstr(str, "{tblack}"))
		str = ft_strreplace(str, "{tblack}", "\033[30m");
	else if (ft_strstr(str, "{tred}"))
		str = ft_strreplace(str, "{tred}", "\033[31m");
	else if (ft_strstr(str, "{tgreen}"))
		str = ft_strreplace(str, "{tgreen}", "\033[32m");
	else if (ft_strstr(str, "{tyellow}"))
		str = ft_strreplace(str, "{tyellow}", "\033[33m");
	else if (ft_strstr(str, "{tblue}"))
		str = ft_strreplace(str, "{tblue}", "\033[34m");
	else if (ft_strstr(str, "{tmagenta}"))
		str = ft_strreplace(str, "{tmagenta}", "\033[35m");
	else if (ft_strstr(str, "{tcyan}"))
		str = ft_strreplace(str, "{tcyan}", "\033[36m");
	else if (ft_strstr(str, "{tgray}"))
		str = ft_strreplace(str, "{tgray}", "\033[37m");
	else
		str = colors_background(str);
	return (str);
}

char	*colors_apply(char *str)
{
	int		leg;
	int		len;

	leg = -1;
	if (str[0])
		leg = (int)ft_strlen(str);
	len = -1;
	while (leg != len)
	{
		if (len != -1)
			leg = len;
		if (ft_strsearch(str, '{') >= 0)
		{
			str = colors_text(str);
		}
		len = (int)ft_strlen(str);
	}
	return (str);
}
