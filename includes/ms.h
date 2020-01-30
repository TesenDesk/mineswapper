#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "ft_printf.h"
#include "libft.h"
#include <time.h>

#define DEBUGGING 0
#define MINE '*'
#define FLAG 'F'
#define WRG_FLAG 'Q'
#define EMPTY '.'

typedef struct		s_ms
{
	char		*map;
	int			width;
	int			size;
	int			mines_amount;
}					t_ms;

int		ft_printf(const char *str, ...);

#endif
