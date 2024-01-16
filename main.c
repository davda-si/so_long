/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:14:51 by davda-si          #+#    #+#             */
/*   Updated: 2023/10/12 17:46:35 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	close_wnd(t_mapper *game)
{
	ft_printf("See ya next time!\n");
	cleaner(game);
	exit (0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mapper	game;

	if (argc != 2)
		error_handle(0, &game);
	if (ft_strnstr(argv[1] + ft_strlen(argv[1]) - 4,
			".ber", ft_strlen(argv[1])) == NULL)
		error_handle(1, &game);
	ft_memset(&game, 0, sizeof(t_mapper));
	if ((alct_map(&game, argv[1]) == 0) || (check_map(&game) == 0))
		error_handle(2, &game);
	cpy_map(&game);
	game.mlx = mlx_init();
	save_img(&game);
	game.wnd = mlx_new_window(game.mlx, \
								ft_strlen_solong(game.map[0]) * 64, \
								game.h * 64, "Sonic Adventure 42");
	map_prnt(&game);
	mlx_hook(game.wnd, 2, 1L << 0, move_p, &game);
	game.img.coin = 0;
	game.img.bot = 0;
	mlx_loop_hook(game.mlx, anim, &game);
	mlx_hook(game.wnd, 17, 0, close_wnd, &game);
	mlx_loop(game.mlx);
}
