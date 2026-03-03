/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 09:45:16 by ecakiray          #+#    #+#             */
/*   Updated: 2026/03/01 17:07:08 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_rectangle
{
	int	width;
	int	hight;
	int	x;
	int	y;
};

char	ft_get_character(struct s_rectangle rectangle);
void	ft_write_rectangle(struct s_rectangle rectangle);
char	ft_is_corner(struct s_rectangle rectangle);
char	ft_is_limit(struct s_rectangle rectangle);
void	ft_putchar(char c);

void	rush(int x, int y)
{
	struct s_rectangle	rectangle;

	if (x < 0 || y < 0)
	{
		return ;
	}
	rectangle.width = x;
	rectangle.hight = y;
	rectangle.x = 0;
	rectangle.y = 0;
	ft_write_rectangle(rectangle);
}

char	ft_is_corner(struct s_rectangle rectangle)
{
	if ((rectangle.x == 0 && rectangle.y == 0)
		|| (rectangle.x == 0 && rectangle.y == (rectangle.hight -1))
		|| (rectangle.y == 0 && rectangle.x == (rectangle.width -1))
		|| (rectangle.x == (rectangle.width -1)
			&& rectangle.y == (rectangle.hight -1))
	)
	{
		return ('o');
	}
	else
	{
		return ('\0');
	}
}

char	ft_is_limit(struct s_rectangle rectangle)
{
	if (rectangle.x == 0 || rectangle.x == (rectangle.width -1)
	)
	{
		return ('|');
	}
	else if (rectangle.y == 0 || rectangle.y == (rectangle.hight -1)
	)
	{
		return ('-');
	}
	else
	{
		return ('\0');
	}
}

void	ft_write_rectangle(struct s_rectangle rectangle)
{
	char	c;

	if (rectangle.width == 0 || rectangle.hight == 0)
	{
		return ;
	}
	while (rectangle.y != rectangle.hight)
	{
		rectangle.x = 0;
		while (rectangle.x != rectangle.width)
		{
			c = ft_get_character(rectangle);
			ft_putchar(c);
			rectangle.x++;
		}
		ft_putchar('\n');
		rectangle.y++;
	}
}

char	ft_get_character(struct s_rectangle rectangle)
{
	char	c;

	c = ft_is_corner(rectangle);
	if (c)
		return (c);
	c = ft_is_limit(rectangle);
	if (c)
		return (c);
	return (' ');
}
