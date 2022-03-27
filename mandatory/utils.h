/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 08:31:35 by kmumm             #+#    #+#             */
/*   Updated: 2022/03/27 14:32:28 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

# define WALL "pic/wall.xpm"
# define FREE "pic/free.xpm"
# define COLLECT "pic/collect.xpm"
# define EXIT "pic/exit.xpm"
# define NPC "pic/npc.xpm"
# define WIN "pic/win.xpm"

# define UP -1
# define DOWN 1
# define LEFT -2
# define RIGHT 2

# define MOVE 0
# define COLLECT_ACT 1
# define EXIT_ACT 2

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_list
{
	char			*content;
	int				len;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_player
{
	int		moves;
	int		coors[2];
}	t_player;

typedef struct s_sprites
{
	void	*wall;
	void	*free;
	void	*collect;
	void	*exit;
	void	*npc;
	void	*win;
}	t_sprites;

typedef struct s_game{
	void		*mlx;
	void		*win;
	int			map_saved_flag;
	t_list		*map;
	int			error_code;
	int			height;
	int			width;
	int			nums[3];
	t_sprites	*sprites;
	int			tile_size;
	t_player	*player;
}	t_game;

int			ft_printf(const char *format, ...);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *str);
char		*ft_strjoin_gnl(char *s1, char *s2);
char		*ft_substr_n(char *str);
int			ft_findn(char *str);
char		*ft_str_read(int fd, char *remainder);
char		*ft_new_remainder(char *str_ost);
char		*get_next_line(int fd);
t_list		*ft_lstnew(char *content);
void		ft_lst_push(t_list **lst, t_list *new_list);
void		ft_lstclear(t_list **lst, void (*del)(void *));
int			ft_lstsize(t_list *lst);
void		ft_lstiter(t_list *lst, void (*f)(void *));
int			ft_strip(char **str);
t_game		*throw_error(t_game *game, int error);
int			close_event(t_game *game);
void		check_arg(int argc, char **argv, t_game *game);
int			key_handler(int key, t_game *game);
void		read_map(char **argv, t_game *game);
void		check_line(t_game *game);
void		check_map(t_game *game);
void		ft_init_pics(t_game *game);
void		ft_draw_tile(t_game *g, void *image, int x, int y);
void		ft_draw_line(t_list *line, t_game *g, int j);
void		ft_draw_map(t_game *g);
char		get_type_by_coors(t_game *g, int x, int y);
int			set_type_by_coors(t_game *g, int x, int y, char type);
void		ft_set_player_coors(t_game *g, int x, int y);
void		player_move(t_game *g, int direction);

#endif
