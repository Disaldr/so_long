/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:49:41 by kmumm             #+#    #+#             */
/*   Updated: 2022/03/22 00:57:36 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	close_event(t_game *game)
{
	char	*errors[11];

	errors[1] = "ERROR WITH ALLOCATING";
	errors[2] = "NO MAP";
	errors[3] = "TOO MANY ARGUMENTS";
	errors[4] = "FILE DOES NOT EXIST";
	errors[5] = "WRONG EXTENSION";
	errors[6] = "MAP IS EMPTY";
	errors[7] = "MAP IS NOT RECTANGULAR";
	errors[8] = "MAP IS NOT BORDERED";
	errors[9] = "ILLEGAL CHARACTERS IN MAP";
	errors[10] = "NOT ENOUGH CHARACTERS IN MAP";
	free(game->player);
	if (game->map_saved_flag)
		ft_lstclear(&game->map, free);
	if (game->error_code == 0)
		exit(EXIT_SUCCESS);
	ft_printf("Error\n%s", errors[game->error_code]);
	exit(EXIT_FAILURE);
	return (0);
}

t_game	*throw_error(t_game *game, int error)
{
	game->error_code = error;
	return (game);
}

void	check_line(t_game *game)
{
	int	i;

	i = 0;
	if (game->map->len != game->height)
		close_event(throw_error(game, 7));
	if (game->map->index == 0 || game->map->index == game->width - 1)
		while (game->map->content[i])
			if (game->map->content[i++] != '1')
				close_event(throw_error(game, 8));
	if (game->map->content[0] != '1'
		|| game->map->content[game->height - 1] != '1')
		close_event(throw_error(game, 8));
	while (game->map->content[i])
	{
		if (game->map->content[i] == 'C')
			++(game->nums[0]);
		else if (game->map->content[i] == 'E')
			++(game->nums[1]);
		else if (game->map->content[i] == 'P')
			++(game->nums[2]);
		else if (game->map->content[i] != '1' && game->map->content[i] != '0')
			close_event(throw_error(game, 9));
		++i;
	}
}

void	check_map(t_game *game)
{
	t_list			*start;

	game->nums[0] = 0;
	game->nums[1] = 0;
	game->nums[2] = 0;
	start = game->map;
	game->height = game->map->len;
	while (game->map != NULL)
	{
		check_line(game);
		game->map = game->map->next;
	}
	if (game->nums[0] * game->nums[1] * game->nums[2] == 0)
		close_event(throw_error(game, 10));
	game->map = start;
}

void	check_arg(int argc, char **argv, t_game *game)
{
	int	length;

	if (argc < 2)
		close_event(throw_error(game, 2));
	if (argc > 2)
		close_event(throw_error(game, 3));
	length = ft_strlen(argv[1]);
	if (read(open(argv[1], O_RDONLY), 0, 0) == -1)
		close_event(throw_error(game, 4));
	if (length <= 4 || argv[1][length - 1] != 'r' || argv[1][length - 2] != 'e'
		|| argv[1][length - 3] != 'b' || argv[1][length - 4] != '.')
		close_event(throw_error(game, 5));
}
