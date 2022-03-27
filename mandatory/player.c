/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:30:29 by kmumm             #+#    #+#             */
/*   Updated: 2022/03/22 04:26:51 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_set_player_coors(t_game *g, int x, int y)
{
	g->player->coors[0] = x;
	g->player->coors[1] = y;
}

void	ft_action(t_game *g, int x, int y, int ACT_TYPE)
{
	t_player	*p;

	p = g->player;
	if (ACT_TYPE == MOVE || ACT_TYPE == COLLECT_ACT)
	{
		ft_draw_tile(g, g->sprites->npc, x, y);
		ft_draw_tile(g, g->sprites->free, p->coors[0], p->coors[1]);
		set_type_by_coors(g, p->coors[1], p->coors[0], '0');
		ft_set_player_coors(g, x, y);
		ft_printf("MOVES: %d\n", ++(g->player->moves));
	}
	if (ACT_TYPE == COLLECT_ACT)
		--g->nums[0];
	if (ACT_TYPE == EXIT_ACT && g->nums[0] == 0)
	{
		ft_printf("MOVES: %d\nWIN", ++(g->player->moves));
		close_event(throw_error(g, 0));
	}
}

void	player_move(t_game *g, int direction)
{
	char		type;
	t_player	*player;
	int			dest[2];

	player = g->player;
	dest[0] = player->coors[0] + direction / 2;
	dest[1] = player->coors[1] + direction % 2;
	type = get_type_by_coors(g, dest[1], dest[0]);
	if (type == -1)
		return ;
	if (type == '0')
		ft_action(g, dest[0], dest[1], MOVE);
	if (type == 'C')
		ft_action(g, dest[0], dest[1], COLLECT_ACT);
	if (type == 'E')
		ft_action(g, dest[0], dest[1], EXIT_ACT);
}
