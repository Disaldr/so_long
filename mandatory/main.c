/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:26:18 by kmumm             #+#    #+#             */
/*   Updated: 2022/03/22 04:23:04 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	key_handler(int key, t_game *game)
{
	if (key == 53)
		close_event(throw_error(game, 0));
	if (key == 13 || key == 126)
		player_move(game, UP);
	if (key == 0 || key == 123)
		player_move(game, LEFT);
	if (key == 1 || key == 125)
		player_move(game, DOWN);
	if (key == 2 || key == 124)
		player_move(game, RIGHT);
	return (0);
}

void	game_init(t_game *game, int argc, char **argv)
{
	game->map_saved_flag = 0;
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		close_event(throw_error(game, 1));
	game->nums[0] = 0;
	game->nums[1] = 0;
	game->nums[2] = 0;
	check_arg(argc, argv, game);
	read_map(argv, game);
	check_map(game);
	game->tile_size = 24;
	game->player->moves = 0;
	game->error_code = 0;
	ft_printf("MOVE: 0\n");
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->tile_size * game->height,
			game->tile_size * game->width, "MYWIN");
	ft_init_pics(game);
	ft_draw_map(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game_init(&game, argc, argv);
	mlx_key_hook(game.win, key_handler, &game);
	mlx_hook(game.win, 17, 0, close_event, &game);
	mlx_loop(game.mlx);
	return (0);
}
