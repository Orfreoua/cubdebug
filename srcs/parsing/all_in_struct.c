/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_in_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:09:05 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/31 20:09:08 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

void	next_params(t_data *data)
{
	int	x;
	int	y;
	int	pos;

	y = 0;
	pos = 0;
	while (data->file.mapy[y][0] != '\0')
	{
		x = 0;
		while (data->file.mapy[y][x] != '\0')
			x++;
		if (x > pos)
			pos = x;
		y++;
	}
	data->args.map.size.height = y;
	data->args.map.size.width = pos;
	data->args.player.dir = data->file.rotate;
}

void	all_in_struct(t_data *data)
{
	data->args.north.path = data->file.textures.north;
	data->args.south.path = data->file.textures.south;
	data->args.east.path = data->file.textures.east;
	data->args.west.path = data->file.textures.west;
	data->args.floor.r = data->file.floor.r;
	data->args.floor.g = data->file.floor.g;
	data->args.floor.b = data->file.floor.b;
	data->args.ceiling.r = data->file.ceiling.r;
	data->args.ceiling.g = data->file.ceiling.g;
	data->args.ceiling.b = data->file.ceiling.b;
	data->args.map.grid = data->file.mapy;
	data->args.player.pos.x = data->file.pos_player.x;
	data->args.player.pos.y = data->file.pos_player.y;
	next_params(data);
}
