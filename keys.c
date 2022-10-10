/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/02/03 16:27:03 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void key_up_down(int key, t_data *data, t_player *player)
{
	if (key == 97)
	{
		player->temp_x = (int) (player->x_double + player->dir_x * MOVE_STEP);
		player->temp_y = (int) (player->y_double + player->dir_y * MOVE_STEP);
		if(dval_map(data, player->temp_x, player->temp_y) == 0)
		{
			player->x_double += player->dir_x * MOVE_STEP;
			player->y_double += player->dir_y * MOVE_STEP;
		}
	}
	else
	{
		player->temp_x = (int) (player->x_double - player->dir_x * MOVE_STEP);
		player->temp_y = (int) (player->y_double - player->dir_y * MOVE_STEP);	
		if(dval_map(data, player->temp_x, player->temp_y) == 0)
		{
			player->x_double -= player->dir_x * MOVE_STEP;
			player->y_double -= player->dir_y * MOVE_STEP;
		}
	}
}

void key_left_right(int key, t_data *data, t_player *player)
{
	if (key == 115)
	{
		player->temp_x = (int) (player->x_double - player->dir_y * MOVE_STEP);
		player->temp_y = (int) (player->y_double + player->dir_x * MOVE_STEP);	
		if(dval_map(data, player->temp_x, player->temp_y) == 0)
		{
			player->x_double -= player->dir_y * MOVE_STEP;
			player->y_double += player->dir_x * MOVE_STEP;
		}
	}
	else
	{
		player->temp_x = (int) (player->x_double + player->dir_y * MOVE_STEP);
		player->temp_y = (int) (player->y_double - player->dir_x * MOVE_STEP);	
		if(dval_map(data, player->temp_x, player->temp_y) == 0)
		{
			player->x_double += player->dir_y * MOVE_STEP;
			player->y_double -= player->dir_x * MOVE_STEP;
		}
	}
}

void key_arrows_lr(int key, t_player *player)
{
	if (key == 65361) 
	{
		double player_dir_x0 = player->dir_x;
		player->dir_x = player->dir_x * cos(ROTATION_ANGLE) - player->dir_y * sin(ROTATION_ANGLE);
		player->dir_y = player_dir_x0 * sin(ROTATION_ANGLE) + player->dir_y * cos(ROTATION_ANGLE);
		double player_plane_x0 = player->plane_x;
		player->plane_x = player->plane_x * cos(ROTATION_ANGLE) - player->plane_y * sin(ROTATION_ANGLE);
		player->plane_y = player_plane_x0 * sin(ROTATION_ANGLE) + player->plane_y * cos(ROTATION_ANGLE);
	}
	if (key == 65363) //arrow right 
	{
		double player_dir_x0 = player->dir_x;
		player->dir_x = player->dir_x * cos(-ROTATION_ANGLE) - player->dir_y * sin(-ROTATION_ANGLE);
		player->dir_y = player_dir_x0 * sin(-ROTATION_ANGLE) + player->dir_y * cos(-ROTATION_ANGLE);
		double player_plane_x0 = player->plane_x;
		player->plane_x = player->plane_x * cos(-ROTATION_ANGLE) - player->plane_y * sin(-ROTATION_ANGLE);
		player->plane_y = player_plane_x0 * sin(-ROTATION_ANGLE) + player->plane_y * cos(-ROTATION_ANGLE);
	}
}

int	key_released(int key, t_data *data)
{
	t_player *player = &data->player;

	if (key == 65307)
		exit_clean(data);
	if (key == 97 || key == 119) 
		key_up_down(key, data, player);
	if (key == 115 || key == 100)
		key_left_right(key, data, player);
	if (key == 65361 || key == 65363)
		key_arrows_lr(key, player);
	player->x_int = (int)player->x_double;
	player->y_int = (int)player->y_double;
	render(data);
	return(0);
}

int	key_down(int key, t_data *data)
{
	t_player *player = &data->player;

	if (key == 97 || key == 119) 
		key_up_down(key, data, player);
	if (key == 115 || key == 100)
		key_left_right(key, data, player);
	if (key == 65361 || key == 65363)
		key_arrows_lr(key, player);
	player->x_int = (int)player->x_double;
	player->y_int = (int)player->y_double;
	render(data);
	return(0);
}
