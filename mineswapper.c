#include "ms.h"

int		die(char *msg)
{
	ft_printf(msg);
	exit (0);
}

int		print_help_or_usage(int mode)
{
	if (mode == 1)
	{
		ft_printf("Welcome to MineSwapper (console version) by jjerde!\n"
				"Use following instructions to play:\nYou can use\n\t"
				"./ms <mode>\n\t\tto start fast game. Replace <mode> "
				"to int:\n\t1 - easy mode (10x10 map, 10 mines);\n\t"
				"2 - medium mode (25x25 map, 75 mines);\n\t"
				"3 - hard mode (50x50 map, 500 mines).\n"
				"When map has been generated, you can see it on screen.\n"
				"Your goal - open all places, which don't have a mine. "
				"When you open a field, number which you see say you "
				"how many mines around this field (in 3x3 square). "
				"Also this field may don't have a number, "
				"this means that this field has no mines around itself and "
				"neighboring fields will be opened automatically. "
				"You can also mark any field as dangerous (if you think so), "
				"this field will be marks with F letter and can't be open. "
				"This is another way to beat the game!\n"
				"Type coordinates (like '5 11') to open it, or add 'f' letter "
				"(like 'f 5 11') to mark or unmark this place as dangerous.\n"
				"When you open all safety places or mark all mines, "
				"YOU will WIN! But be careful, don't blow up yourself!\n"
				"Type 'q' if you want end the game.\nGood luck! :)\n\n");
	}
	else if (!mode)
		ft_printf("Hello! Use './ms h' to see help page! ;)\n");
	else
		ft_printf("Huh?? Don't understand you, type './ms h' for help! :]");
	return (0);
}

void	mines_generator(t_ms *ms)
{
	int		i;
	int		coords;

	srand(time(NULL));
	i = 1;
	while (i <= ms->mines_amount)
	{
		coords = rand() % ms->size;
		if (ms->map[coords] == '*')
			continue ;
		ms->map[coords] = '*';
		++i;
	}
}

void	print_numb(t_ms *ms)
{
	int		i;

	i = -1;
	write(1, "   ", 3);
	while (++i < ms->width)
	{
		ft_putnbr((i + 1) % 10);
	}
}

void	print_map_sicret(t_ms *ms)
{
	int		i;
	int		l;
	char	curr;

	i = -1;
	l = 1;
	curr = EMPTY;
	while (++i < ms->size)
	{
		if (!i)
			print_numb(ms);
		if (!(i % ms->width))
		{
			write(1, "\033[0m\n", 5);
			if (l < 10)
				write(1, "0", 1);
			ft_putnbr(l);
			write(1, " ", 1);
			++l;
		}
		if (curr != ms->map[i])
		{
			curr = ms->map[i];
			if (curr == FLAG || curr == WRG_FLAG)
				write(1, "\033[36m", 5);
			else if (curr >= '0' && curr <= '9')
				write(1, "\033[33m", 5);
			else
				write(1, "\033[0m", 4);
		}
		if (ms->map[i] == WRG_FLAG)
			write(1, "F", 1);
		else if (ms->map[i] == MINE)
			write(1, ".", 1);
		else
			write(1, &ms->map[i], 1);
	}
	write(1, "\n", 1);
}

void	print_map(t_ms *ms)
{
	int		i;
	int		l;
	char	curr;

	i = -1;
	l = 1;
	curr = EMPTY;
	while (++i < ms->size)
	{
		if (!i)
			print_numb(ms);
		if (!(i % ms->width))
		{
			write(1, "\033[0m\n", 5);
			curr = EMPTY;
			if (l < 10)
				write(1, "0", 1);
			ft_putnbr(l);
			write(1, " ", 1);
			++l;
		}
		if (curr != ms->map[i])
		{
			curr = ms->map[i];
			if (curr == FLAG)
				write(1, "\033[36m", 5);
			else if (curr == MINE)
				write(1, "\033[31m", 5);
			else if (curr >= '0' && curr <= '9')
				write(1, "\033[33m", 5);
			else
				write(1, "\033[0m", 4);
		}
		write(1, &ms->map[i], 1);
	}
	write(1, "\033[0m\n", 5);
}

int		map_generator(t_ms *ms, char mode)
{
	ft_bzero(ms, sizeof(t_ms));
	if (mode == '1')
	{
		ms->width = 10;
		ms->size = 100;
		ms->mines_amount = 10;
	}
	else if (mode == '2')
	{
		ms->width = 25;
		ms->size = 625;
		ms->mines_amount = 75;
	}
	else if (mode == '3')
	{
		ms->size = 2500;
		ms->width = 50;
		ms->mines_amount = 500;
	}
	if (!(ms->map = ft_memalloc(sizeof(char) * (ms->size + 1))))
		return (die("Oooops! Some nasty error was occurred when I tried to allocate memory! Pah!\n"));
	ft_memset(ms->map, EMPTY, ms->size);
	mines_generator(ms);
	return (1);
}

int		count_around(t_ms *ms, int cord)
{
	int	here;
	int	count;

	count = 0;
	here = cord - ms->width - 1;
	/*
	* o..
	* ...
	* ...
	*/
	if (here >= 0 && cord % ms->width)
		if (ms->map[here] == MINE || ms->map[here] == FLAG)
			++count;
	++here;
	/*
	* .o.
	* ...
	* ...
	*/
	if (here >= 0)
		if (ms->map[here] == MINE || ms->map[here] == FLAG)
			++count;
	++here;
	/*
	* ..o
	* ...
	* ...
	*/
	if (here >= 0 && here % ms->width)
		if (ms->map[here] == MINE || ms->map[here] == FLAG)
			++count;
	here = cord - 1;
	/*
	 * ...
	 * o..
	 * ...
	 */
	if (cord % ms->width)
		if (ms->map[here] == MINE || ms->map[here] == FLAG)
			++count;
	here = cord + 1;
	/*
	 * ...
	 * ..o
	 * ...
	 */
	if (here % ms->width)
		if (ms->map[here] == MINE || ms->map[here] == FLAG)
			++count;
	here = cord + ms->width - 1;
	/*
	 * ...
	 * ...
	 * o..
	 */
	if (here < ms->size && cord % ms->width)
		if (ms->map[here] == MINE || ms->map[here] == FLAG)
			++count;
	++here;
	/*
	 * ...
	 * ...
	 * .o.
	 */
	if (here < ms->size)
		if (ms->map[here] == MINE || ms->map[here] == FLAG)
			++count;
	++here;
	/*
	 * ...
	 * ...
	 * ..o
	 */
	if (here < ms->size && here % ms->width)
		if (ms->map[here] == MINE || ms->map[here] == FLAG)
			++count;
	return (count);
}

int		open_field(t_ms *ms, int i)
{
	int	this;
	int	pos;

	if (ms->map[i] == MINE)
		return (0);
	if (ms->map[i] != EMPTY)
		return (1);
	if (!(this = count_around(ms, i)))
	{
		ms->map[i] = ' ';
		// up down left right
		if (i % ms->width)
			open_field(ms, i - 1);
		if ((pos = i - ms->width) >= 0)
		{
			open_field(ms, pos);
			if (--pos >= 0 && i % ms->width)
				open_field(ms, pos);
			if ((pos = pos + 2) % ms->width)
				open_field(ms, pos);
		}
		if ((i + 1) % ms->width)
			open_field(ms, i + 1);
		if ((pos = i + ms->width) < ms->size)
		{
			open_field(ms, pos);
			if (i % ms->width)
				open_field(ms, pos - 1);
			if (++pos < ms->size && pos % ms->width)
				open_field(ms, pos);
		}
	}
	else
		ms->map[i] = (char)(this + '0');
	return (1);
}

void	place_flag(t_ms *ms, int i)
{
	if (ms->map[i] == EMPTY)
		ms->map[i] = WRG_FLAG;
	else if (ms->map[i] == MINE)
		ms->map[i] = FLAG;
	else if (ms->map[i] == FLAG)
		ms->map[i] = MINE;
	else if (ms->map[i] == WRG_FLAG)
		ms->map[i] = EMPTY;
}

int			reader(t_ms *ms)
{
	int		tmp;
	char	buff[BUFF_SIZE + 1];
	int		cord;
	int		mode;
	int		i;

	mode = 0;
	i = 0;
	tmp = read(0, buff, BUFF_SIZE);
	buff[tmp] = 0;
	if (buff[i] == 'q' || buff[i] == 'Q')
	{
		ft_printf("{tcyan}Just leave? Ok, I show you all mines...{r}\n");
		print_map(ms);
		die("Exiting application...\n");
	}
	else if (buff[i] == 'f' || buff[i] == 'F')
	{
		++i;
		mode = 1;
	}
	while (buff[i] == ' ')
		++i;
	if ((tmp = ft_atoi(&buff[i])) > 0 && --tmp < ms->width)
		cord = tmp * ms->width;
	else
		cord = -1;
	if (cord >= 0 && (tmp = ft_atoi(&buff[i + ft_strclen(&buff[i], ' ')])) > 0 && --tmp < ms->width)
		cord = cord + tmp;
	else
		cord = -1;
	if (cord < 0)
		ft_printf("Huh? Type a coords please......\n");
	else
	{
		if (mode)
			place_flag(ms, cord);
		else
			return (open_field(ms, cord));
	}
	return (1);
}

int		start_ms(char mode)
{
	t_ms	ms_data;
	int		opened;

	if (!(map_generator(&ms_data, mode)))
		return (ft_printf("Oooops! Map generation failtue.... Sorry about that.... :'[\n"));
	if (DEBUGGING)
		print_map(&ms_data);
	else print_map_sicret(&ms_data);
	while ((opened = reader(&ms_data)) && ((ft_strchr(ms_data.map, EMPTY) && ft_strchr(ms_data.map, MINE)) || ft_strchr(ms_data.map, WRG_FLAG)))
	{
		if (DEBUGGING)
			print_map(&ms_data);
		else print_map_sicret(&ms_data);
	}
	if (!opened)
		ft_printf("\033[31mKABOOOM!!!! You are blow up on mine! So sad! :'(\033[0m\n");
	else
		ft_printf("\033[1;32mWow!! YOU WON!!! Congratulations!!!!\033[0m\n");
	print_map(&ms_data);
	ft_strdel(&ms_data.map);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (print_help_or_usage(0));
	if (argv[1][0] == 'h')
		return (print_help_or_usage(1));
	if (argv[1][0] == '1' || argv[1][0] == '2' || argv[1][0] == '3')
		start_ms(argv[1][0]);
	else
		return (print_help_or_usage(2));
}
