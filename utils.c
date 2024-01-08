/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:31:54 by davda-si          #+#    #+#             */
/*   Updated: 2023/10/12 17:34:06 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

size_t	ft_strlen_solong(const char *s)
{
	size_t	a;

	a = 0;
	while (s[a] != '\0' && s[a] != '\n')
	{
		a++;
	}
	return (a);
}

int	ft_valid(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C' && c != '\n' \
		&& c != 'B')
		return (0);
	return (1);
}

void	add_player(t_mapper *game, int i, int j)
{
	game->p++;
	game->p_x = j;
	game->p_y = i;
}

void	cleaner(t_mapper *game)
{
	int	i;

	i = 0;
	mlx_destroy_image(game->mlx, game->img.still);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.man);
	while (i < 3)
	{
		mlx_destroy_image(game->mlx, game->img.s[i]);
		mlx_destroy_image(game->mlx, game->img.r[i]);
		i++;
	}
	i = 0;
	while (i < 8)
		mlx_destroy_image(game->mlx, game->img.c[i++]);
	i = 0;
	while (i < 2)
		mlx_destroy_image(game->mlx, game->img.b[i++]);
	free_map(game->map);
	mlx_destroy_window(game->mlx, game->wnd);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

unsigned int	timer(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
