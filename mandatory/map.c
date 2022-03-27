/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 04:02:24 by kmumm             #+#    #+#             */
/*   Updated: 2022/03/15 19:57:52 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	read_map(char **argv, t_game *game)
{
	int		file;
	t_list	*start;
	char	*line;

	file = open(argv[1], O_RDONLY);
	line = get_next_line(file);
	if (!line)
		close_event(throw_error(game, 6));
	ft_strip(&line);
	game->map = ft_lstnew(line);
	if (!game->map)
		close_event(throw_error(game, 1));
	start = game->map;
	while (line)
	{	
		line = get_next_line(file);
		if (!line)
			break ;
		ft_strip(&line);
		ft_lst_push(&game->map, ft_lstnew(line));
	}
	game->width = game->map->index + 1;
	game->map = start;
	game->map_saved_flag = 1;
}

char	get_type_by_coors(t_game *g, int x, int y)
{
	t_list	*map;
	int		i;

	map = g->map;
	while (map != NULL)
	{
		if (map->index == x)
		{
			i = 0;
			while (map->content[i])
			{
				if (i == y)
					return (map->content[i]);
				++i;
			}
			return (-1);
		}
		map = map->next;
	}
	return (-1);
}

int	set_type_by_coors(t_game *g, int x, int y, char type)
{
	t_list	*map;
	int		i;

	map = g->map;
	if (x < 0 || y < 0 || x >= g->width || y >= g->height)
		return (-1);
	while (map != NULL)
	{
		if (map->index == x)
		{
			i = 0;
			while (map->content[i])
			{
				if (i == y)
				{
					map->content[i] = type;
					return (1);
				}
				++i;
			}
			return (-1);
		}
		map = map->next;
	}
	return (-1);
}

void	ft_draw_map(t_game *g)
{
	t_list	*map;
	int		i;

	map = g->map;
	i = g->height;
	mlx_clear_window(g->mlx, g->win);
	while (map != NULL)
	{
		ft_draw_line(map, g, map->index);
		map = map->next;
	}
}
