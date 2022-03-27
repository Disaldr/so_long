/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:40:37 by kmumm             #+#    #+#             */
/*   Updated: 2022/03/22 04:29:38 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_uitoa(unsigned int n)
{
	char	dest[10];
	int		i;

	dest[9] = '\0';
	i = 8;
	while (n >= 10)
	{
		dest[i--] = n % 10 + 48;
		n = n / 10;
	}
	dest[i] = n + 48;
	return (ft_strdup(&dest[i]));
}

int	ft_render(t_game *game)
{
	char	*scores;
	int		i;
	int		j;
	int		limit;

	i = 0;
	scores = ft_uitoa(game->player->moves);
	limit = ft_strlen(scores) * 10 + 75;
	while (i != 25)
	{
		j = 0;
		while (j != limit)
			mlx_pixel_put(game->mlx, game->win, j++, i, 0);
		++i;
	}
	mlx_string_put(game->mlx, game->win, 10, 0, 16777215, *&"MOVES:");
	mlx_string_put(game->mlx, game->win, 70, 0, 16777215, scores);
	free(scores);
	return (0);
}

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
	ft_render(game);
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
	game->game_fps = 0;
	check_arg(argc, argv, game);
	read_map(argv, game);
	check_map(game);
	game->tile_size = 24;
	game->player->moves = 0;
	game->error_code = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->tile_size * game->height,
			game->tile_size * game->width, "MYWIN");
	ft_init_pics(game);
	ft_draw_map(game);
	ft_render(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game_init(&game, argc, argv);
	mlx_key_hook(game.win, key_handler, &game);
	mlx_hook(game.win, 17, 0, close_event, &game);
	mlx_loop_hook(game.mlx, player_animation, &game);
	mlx_loop(game.mlx);
	return (0);
}
