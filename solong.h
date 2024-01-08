/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:12:39 by davda-si          #+#    #+#             */
/*   Updated: 2023/10/12 17:34:47 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "./libs/mlx_linux/mlx.h"
# include "./libs/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/time.h>

typedef struct s_graph
{
	void	*sonic;
	void	*still;
	void	*s[3];
	void	*r[3];
	void	*floor;
	void	*exit;
	void	*c[9];
	void	*wall;
	void	*egg;
	void	*man;
	void	*b[3];
	int		bot;
	int		coin;
	int		frame;
	int		direct;
}			t_graph;

typedef struct s_bot
{
	int	x;
	int	y;
}			t_bot;

typedef struct s_mapper
{
	char	**map;
	void	*mlx;
	void	*wnd;
	int		c;
	int		e;
	int		p;
	int		p_x;
	int		p_y;
	int		l;
	int		m;
	int		b;
	int		h;
	int		cp;
	int		ep;
	t_graph	img;
	t_bot	bot[100000];
}			t_mapper;

int				main(int argc, char **argv);
int				check_map(t_mapper *game);
int				alct_map(t_mapper *game, char *argv);
size_t			ft_strlen_solong(const char *s);
int				ft_valid(char c);
void			add_player(t_mapper *game, int i, int j);
void			cpy_map(t_mapper *game);
void			error_handle(int i, t_mapper *game);
void			free_map(char **map);
void			save_img(t_mapper *game);
void			map_prnt(t_mapper *game);
int				eng(t_mapper *game);
int				move_p(int cd, t_mapper *game);
void			cleaner(t_mapper *game);
int				coin_eng(t_mapper *game);
unsigned int	timer(void);
int				anim(t_mapper *game);
void			save_frames(t_mapper *game);

#endif
