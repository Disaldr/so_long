/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:50:34 by kmumm             #+#    #+#             */
/*   Updated: 2022/03/22 04:07:09 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_init_pics(t_game *game)
{
	int	width;
	int	height;

	game->sprites = malloc(sizeof(t_sprites));
	game->sprites->wall = mlx_xpm_file_to_image(game->mlx,
			WALL, &width, &height);
	game->sprites->free = mlx_xpm_file_to_image(game->mlx,
			FREE, &width, &height);
	game->sprites->npc = mlx_xpm_file_to_image(game->mlx,
			NPC, &width, &height);
	game->sprites->collect = mlx_xpm_file_to_image(game->mlx,
			COLLECT, &width, &height);
	game->sprites->exit = mlx_xpm_file_to_image(game->mlx,
			EXIT, &width, &height);
	game->sprites->win = mlx_xpm_file_to_image(game->mlx,
			WIN, &width, &height);
	game->sprites->enemy = mlx_xpm_file_to_image(game->mlx,
			ENEMY, &width, &height);
	init_player_sprites(game);
}

void	ft_draw_tile(t_game *g, void *image, int x, int y)
{
	int	x_coord;
	int	y_coord;

	x_coord = x * g->tile_size;
	y_coord = y * g->tile_size;
	mlx_put_image_to_window(g->mlx, g->win, image, x_coord, y_coord);
}

void	ft_draw_line(t_list *line, t_game *g, int j)
{
	int			i;
	int			s;
	t_sprites	*sp;

	sp = g->sprites;
	s = g->tile_size;
	i = -1;
	while (line && line->content[++i] != '\0')
	{
		if (line->content[i] == '1')
			ft_draw_tile(g, sp->wall, i, j);
		else if (line->content[i] == '0')
			ft_draw_tile(g, sp->free, i, j);
		else if (line->content[i] == 'A')
			ft_draw_tile(g, sp->enemy, i, j);
		else if (line->content[i] == 'P')
		{
			ft_set_player_coors(g, i, j);
			ft_draw_tile(g, sp->npc, i, j);
		}
		else if (line->content[i] == 'C')
			ft_draw_tile(g, sp->collect, i, j);
		else if (line->content[i] == 'E')
			ft_draw_tile(g, sp->exit, i, j);
	}
}
