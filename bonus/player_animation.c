/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:16:44 by kmumm             #+#    #+#             */
/*   Updated: 2022/03/22 04:17:44 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_player_sprites(t_game *game)
{
	int			w;
	int			h;
	t_sprites	*sp;

	sp = game->sprites;
	sp->player_sprites[0] = mlx_xpm_file_to_image(
			game->mlx, NPC1, &w, &h);
	sp->player_sprites[1] = mlx_xpm_file_to_image(
			game->mlx, NPC2, &w, &h);
	sp->player_sprites[2] = mlx_xpm_file_to_image(
			game->mlx, NPC3, &w, &h);
	sp->player_sprites[3] = mlx_xpm_file_to_image(
			game->mlx, NPC4, &w, &h);
	sp->player_sprites[4] = mlx_xpm_file_to_image(
			game->mlx, NPC5, &w, &h);
	sp->player_sprites[5] = mlx_xpm_file_to_image(
			game->mlx, NPC6, &w, &h);
	sp->player_sprites[6] = mlx_xpm_file_to_image(
			game->mlx, NPC7, &w, &h);
	sp->player_sprites[7] = mlx_xpm_file_to_image(
			game->mlx, NPC8, &w, &h);
	sp->npc = sp->player_sprites[0];
}

int	player_animation(t_game *g)
{
	int	frame_number;
	int	fps;

	frame_number = g->game_fps;
	if (frame_number % FPS == 0)
	{
		fps = frame_number / FPS;
		ft_draw_tile(g, g->sprites->player_sprites[fps],
			g->player->coors[0], g->player->coors[1]);
	}
	++g->game_fps;
	if (g->game_fps == FPS * 8)
		g->game_fps = 0;
	return (0);
}
