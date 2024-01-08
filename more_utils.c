/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:56:16 by davda-si          #+#    #+#             */
/*   Updated: 2023/10/12 17:33:15 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	bot_eng(t_mapper *game)
{
	static unsigned int	i = 0;

	if (i == 0)
		i = timer();
	if ((timer() - i) < 200)
		return ;
	i = timer();
	if (game->img.bot == 1)
		game->img.bot = 0;
	else
		game->img.bot = 1;
	game->img.b[2] = game->img.b[game->img.bot];
}

static void	movemnt(t_mapper *game, int x, int y, int i)
{
	if (game->map[game->bot[i].y + y][game->bot[i].x + x] == 'P')
	{
		ft_printf("You died...\n");
		cleaner(game);
		exit (0);
	}
	if (game->map[game->bot[i].y + y][game->bot[i].x + x] == '0')
	{
		game->map[game->bot[i].y][game->bot[i].x] = '0';
		game->bot[i].y += y;
		game->bot[i].x += x;
		game->map[game->bot[i].y][game->bot[i].x] = 'B';
	}
}

static void	bot_anim(t_mapper *game)
{
	int			i;
	int			n;
	static int	j = 0;

	i = 0;
	if (j == 0)
		j = timer();
	if ((timer() - j) < 500)
		return ;
	j = timer();
	n = rand() % 4;
	while (i < game->b)
	{
		if (n == 0)
			movemnt(game, 0, -1, i);
		if (n == 1)
			movemnt(game, -1, 0, i);
		if (n == 2)
			movemnt(game, 0, 1, i);
		if (n == 3)
			movemnt(game, 1, 0, i);
		i++;
	}
}

int	anim(t_mapper *game)
{
	bot_anim(game);
	coin_eng(game);
	bot_eng(game);
	return (0);
}

void	save_frames(t_mapper *game)
{
	int	p;

	p = 64;
	game->img.s[0] = mlx_xpm_file_to_image(game->mlx, "textures/s1.xpm", &p,
			&p);
	game->img.s[1] = mlx_xpm_file_to_image(game->mlx, "textures/s2.xpm", &p, 
			&p);
	game->img.s[2] = mlx_xpm_file_to_image(game->mlx, "textures/s3.xpm", &p, 
			&p);
	game->img.r[0] = mlx_xpm_file_to_image(game->mlx, "textures/r1.xpm", &p, 
			&p);
	game->img.r[1] = mlx_xpm_file_to_image(game->mlx, "textures/r2.xpm", &p, 
			&p);
	game->img.r[2] = mlx_xpm_file_to_image(game->mlx, "textures/r3.xpm", &p, 
			&p);
}
