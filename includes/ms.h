#ifndef MS_H
# define MS_H

#include "ft_printf.h"
#include "libft.h"
#include <time.h>
#include "mlx.h"

#define DEBUGGING 0
#define MINE '*'
#define FLAG 'F'
#define WRG_FLAG 'Q'
#define EMPTY '.'
# define WHITE_COLOR	0x00FFFFFF
# define YELLOW_COLOR	0x00FFFF00
# define RED_B_COLOR	0x00F85C50
# define ORANGE_COLOR	0x00FC9A40
# define RED_COLOR		0x00FF0000
# define SCREEN_WIDTH	1600
# define SCREEN_HEIGHT	1200
# define SCREEN_TITLE	"mineswapper by jjerde!"


typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
}						t_mlx;

typedef struct		s_ms
{
	t_mlx		mlx;
	char		*map;
	int			width;
	int			size;
	int			mines_amount;
	int			selected_opt;
	int			opened_opt;
	int			opened_diff;
	int			config[3];
}					t_ms;

typedef struct			s_drawing
{
	int					x;
	int					y;
	int					color;
	int					w;
	int					h;
}						t_drawing;

typedef int (*t_func)(t_mlx *, t_drawing, void (*)(t_mlx *, t_drawing *));

typedef enum			e_buttons
{
	ZOOM_X_PLUS = 92,
	ZOOM_X_MINUS = 89,
	ZOOM_Y_PLUS = 88,
	ZOOM_Y_MINUS = 86,
	ZOOM_Z_PLUS = 85,
	ZOOM_Z_MINUS = 83,
	ROTATE_X_MINUS = 1,
	ROTATE_X_PLUS = 13,
	ROTATE_Y_MINUS = 0,
	ROTATE_Y_PLUS = 2,
	ROTATE_Z_PLUS = 14,
	ROTATE_Z_MINUS = 12,
	ROTATE_RESET = 48,
	POSITION_RESET = 36,
	PLUS = 24,
	MINUS = 27,
	ZOOM_RESET = 51,
	LEFT = 123,
	RIGHT,
	DOWN,
	UP,
	HUD = 4,
	SCALE_RESET = 82,
	ESC = 53
}						t_buttons;

int		ft_printf(const char *str, ...);

#endif
