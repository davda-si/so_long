/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:48:34 by davda-si          #+#    #+#             */
/*   Updated: 2023/10/12 17:20:40 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	save_coins(t_mapper *game)
{
	int	p;

	p = 64;
	game->img.c[0] = mlx_xpm_file_to_image(game->mlx, "textures/c1.xpm", \
											&p, &p);
	game->img.c[1] = mlx_xpm_file_to_image(game->mlx, "textures/c3.xpm", \
											&p, &p);
	game->img.c[2] = mlx_xpm_file_to_image(game->mlx, "textures/c2.xpm", \
											&p, &p);
	game->img.c[3] = mlx_xpm_file_to_image(game->mlx, "textures/c4.xpm", \
											&p, &p);
	game->img.c[4] = mlx_xpm_file_to_image(game->mlx, "textures/c5.xpm", \
											&p, &p);
	game->img.c[5] = mlx_xpm_file_to_image(game->mlx, "textures/c6.xpm", \
											&p, &p);
	game->img.c[6] = mlx_xpm_file_to_image(game->mlx, "textures/c7.xpm", \
											&p, &p);
	game->img.c[7] = mlx_xpm_file_to_image(game->mlx, "textures/c8.xpm", \
											&p, &p);
	game->img.c[8] = game->img.c[0];
}

int	coin_eng(t_mapper *game)
{
	static unsigned int	i = 0;

	if (i == 0)
		i = timer();
	if (timer() - i < 50)
		return (0);
	i = timer();
	if (game->img.coin == 7)
		game->img.coin = 0;
	else
		game->img.coin++;
	game->img.c[8] = game->img.c[game->img.coin];
	map_prnt(game);
	return (0);
}

void	save_img(t_mapper *game)
{
	int	p;

	p = 64;
	game->img.sonic = mlx_xpm_file_to_image(game->mlx, "textures/sonic.xpm", \
											&p, &p);
	game->img.still = game->img.sonic;
	save_frames(game);
	game->img.egg = mlx_xpm_file_to_image(game->mlx, "textures/egg.xpm", &p,
			&p);
	game->img.b[0] = mlx_xpm_file_to_image(game->mlx, "textures/b1.xpm", &p, 
			&p);
	game->img.b[1] = mlx_xpm_file_to_image(game->mlx, "textures/b2.xpm", &p, 
			&p);
	game->img.b[2] = game->img.b[0];
	save_coins(game);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", \
											&p, &p);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", \
											&p, &p);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", \
											&p, &p);
	game->img.man = game->img.egg;
}

static void	putimg(t_mapper *game, int i, int j)
{
	char	*str;

	str = ft_itoa(game->m);
	mlx_string_put(game->mlx, game->wnd, 10, 20, 0xffffffff, str);
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->wnd, game->img.wall, \
				j * 64, i * 64);
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->wnd, game->img.floor, \
				j * 64, i * 64);
	if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->wnd, game->img.egg, \
				j * 64, i * 64);
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->wnd, game->img.c[8], \
				j * 64, i * 64);
	if (game->map[i][j] == 'B')
		mlx_put_image_to_window(game->mlx, game->wnd, game->img.b[2], \
				j * 64, i * 64);
	free(str);
}

void	map_prnt(t_mapper *game)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(game->mlx, game->wnd);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			putimg(game, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->wnd, game->img.sonic, \
	game->p_x * 64, game->p_y * 64);
}
