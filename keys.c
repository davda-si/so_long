/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:57:28 by davda-si          #+#    #+#             */
/*   Updated: 2023/10/13 13:04:56 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	need_space(int x, int y, t_mapper *game)
{
	if (game->map[game->p_y + y][game->p_x + x] == '0' 
		|| game->map[game->p_y + y][game->p_x + x] == 'C')
	{
		game->map[game->p_y][game->p_x] = '0';
		game->p_y += y;
		game->p_x += x;
		game->map[game->p_y][game->p_x] = 'P';
		game->m++;
	}
}

static void	found_bot(t_mapper *game)
{
	ft_printf("You died...\n");
	cleaner(game);
	exit (0);
}

static void	movement(int x, int y, t_mapper *game)
{
	if (x == 1)
		game->img.direct = 1;
	if (x == -1)
		game->img.direct = -1;
	if (game->img.direct == 1)
		game->img.sonic = game->img.s[game->img.frame++ % 3];
	if (game->img.direct == -1)
		game->img.sonic = game->img.r[game->img.frame++ % 3];
	if (game->map[game->p_y + y][game->p_x + x] == 'C')
	{
		game->c--;
		if (game->c == 0)
			game->img.egg = game->img.exit; 
	}
	if (game->map[game->p_y + y][game->p_x + x] == 'B')
		found_bot(game);
	if (game->map[game->p_y + y][game->p_x + x] == 'E' && game->c == 0)
	{
		ft_printf("YOU WON!!!!!\n");
		cleaner(game);
		exit (0);
	}
	need_space(x, y, game);
	map_prnt(game);
}

int	move_p(int cd, t_mapper *game)
{
	if (cd == 119)
		movement(0, -1, game);
	if (cd == 97)
		movement(-1, 0, game);
	if (cd == 115)
		movement(0, 1, game);
	if (cd == 100)
		movement(1, 0, game);
	if (cd == 65307)
	{
		ft_printf("See ya next time!\n");
		cleaner(game);
		exit(0);
	}
	return (0);
}

int	eng(t_mapper *game)
{
	mlx_key_hook(game->wnd, move_p, game);
	return (0);
}
