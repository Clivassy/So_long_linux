#ifndef SOLONG_H

#define	SOLONG_H
# include <stdlib.h>
# include "mlx.h"
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <X11/keysym.h>

#define BUFFER_SIZE 100

typedef struct s_game
{

    int p_x;
    int p_y;
    void	*mlx_ptr;
	void	*mlx_win;
    void    *image;
    void    *img_wall;
    void    *img_floor;
    void    *img_exit;
    void    *img_player;
    void    *img_collect;
    int     length;
    char    **map;
    int     width;
    int     move;
    int     player;
    int     collector;
    int     exit;
} t_game;

/* Checker input && map */
int     ft_count_lines(char *file);
void    ft_map_checker(t_game *data);
void    ft_check_inside_map(t_game *data);
void    ft_check_walls(t_game *data);
void    ft_check_one_line(char *line, t_game *data);
void    t_check_columns(t_game *data);
void    ft_check_c_and_e(int index, int j, t_game *data);
int     ft_is_one_player(t_game *data);
char    **ft_create_map( char *file);
int     ft_check_lines_len(t_game *data);

/* Draw map */
int     ft_draw_map(t_game *data);
void    ft_img_init(t_game *data);
void    *ft_convert_to_img(char *img, t_game *data);
void    img_draw(t_game *data, void *img, int x, int y);

/* Game */
void    ft_get_player_pos(t_game *data);
int     ft_close_window(int keycode, t_game *data);
void    ft_init_struc(t_game *data, char *file);
int     ft_so_long(t_game *data);
int     move_event(int keycode, t_game *data);
void    ft_move_down(t_game *data);
void    ft_move_up(t_game *data);
void    ft_move_right(t_game *data);
void    ft_move_left(t_game *data);
int     ft_exit(t_game *data);

/* Errors */
void    ft_input_error(char *msg);
void    ft_map_error(char *msg, t_game *data);
char    **ft_free(char **tab);

/* GNL */
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_search(char *s);
char	*ft_get_one_line(char *buffer);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_get_remainder(char *buffer);
char	*ft_read_buff(int fd, char *save);
int     ft_strlen(char *s);

/* LIBFT */
char	*ft_itoa(int n);
void    ft_putnbr(int nb);
void    ft_putstr_fd(char *s, int fd);
char    **ft_split(char *s, char c);
char    *ft_strdup(char *s);
void    ft_putendl_fd(char *s, int fd);
char    *ft_strrchr(char *s, int c);
int     ft_strcmp(char *s1, char *s2);
#endif