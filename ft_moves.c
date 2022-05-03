#include "so_long.h"
void    ft_get_player_pos(t_game *data)
{
    int x;
    int y;

    y = 0;
    while(data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (data->map[y][x] == 'P')
            {
                data->p_x = x;
                data->p_y = y;
            }
            x++;
        }
        y++;
    }
   // printf("%d %d",data->p_x, data->p_y);
}

void    ft_move_up(t_game *data)
{
    ft_get_player_pos(data);
    data->p_y--;
    //printf("%d\n", data->move);
    if (data->map[data->p_y][data->p_x] != '1')
    {
        if (data->map[data->p_y][data->p_x] == 'E')
        {   
            printf("Game end");
            ft_exit(data);   
        }
        printf("%d\n", data->move);
        //if (data->map[data->p_y][data->p_x] == 'C')
          //  printf("Good job! You caught an item!\n");
        data->map[data->p_y][data->p_x] = 'P';
        img_draw(data, data->img_player, data->p_x, data->p_y);
        data->map[data->p_y + 1][data->p_x] = '0';
        img_draw(data, data->img_floor, data->p_x, (data->p_y +1));
        data->move++;
        //printf("%d\n", data->move);
    }
}

void ft_move_down(t_game *data)
{
    ft_get_player_pos(data);
    data->p_y++;
   // printf("%d\n", data->move);
    if (data->map[data->p_y][data->p_x] != '1')
    {
        if (data->map[data->p_y][data->p_x] == 'E')
        {   
            printf("Game end");
            ft_exit(data);   
        }
        //if (data->map[data->p_y][data->p_x] == 'C')
          //  printf("Good job! You caught an item!\n");
        printf("%d\n", data->move);
        data->map[data->p_y][data->p_x] = 'P';
        img_draw(data, data->img_player, data->p_x, data->p_y);
        data->map[data->p_y - 1][data->p_x] = '0';
        img_draw(data, data->img_floor, data->p_x, (data->p_y - 1));
        data->move++;
       // printf("%d\n", data->move);
    }
}

void    ft_move_right(t_game *data)
{
    ft_get_player_pos(data);
    data->p_x++;
    //printf("%d\n", data->move);
    if (data->map[data->p_y][data->p_x] != '1')
    {
        if (data->map[data->p_y][data->p_x] == 'E')
        {   
            printf("Game end");
            ft_exit(data);   
        }
       // if (data->map[data->p_y][data->p_x] == 'C')
         //   printf("Good job! You caught an item!\n");
        printf("%d\n", data->move);
        data->map[data->p_y][data->p_x] = 'P';
        img_draw(data, data->img_player, data->p_x, data->p_y);
        data->map[data->p_y][data->p_x - 1] = '0';
        img_draw(data, data->img_floor, (data->p_x - 1), data->p_y);
        data->move++;
      //  printf("%d\n", data->move);
    }
}

void ft_move_left(t_game *data)
{
   ft_get_player_pos(data);
    data->p_x--; 
    if (data->map[data->p_y][data->p_x] != '1')
    {
        if (data->map[data->p_y][data->p_x] == 'E')
        {   
            printf("Game end");
            ft_exit(data);   
        }
        printf("%d\n", data->move);
       // if (data->map[data->p_y][data->p_x] == 'C')
         //   printf("Good job! You caught an item!\n");
        data->map[data->p_y][data->p_x] = 'P';
        img_draw(data, data->img_player, data->p_x, data->p_y);
        data->map[data->p_y][data->p_x +1] = '0';
        img_draw(data, data->img_floor, (data->p_x + 1), data->p_y);
        data->move++;
       //printf("%d\n", data->move);
    }
}