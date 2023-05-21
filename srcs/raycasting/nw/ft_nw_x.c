/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nw_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:07:01 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/31 19:34:20 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

double	*nw_x(t_data *data, t_point decimal, double angle)
{
	int		i;
	double	*hypo;

	i = 1;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	hypo[0] = decimal.x / cos(angle - M_PI);
	data->args.player.hit1.x = (int)data->args.player.pos.x;
	data->args.player.hit1.y = data->args.player.pos.y - sqrt(hypo[0] * hypo[0] - decimal.x * (decimal.x));
	while (data->args.player.hit1.y >= 0 && data->args.player.hit1.x >= 0
		&& check_hit(data, 'w', data->args.player.hit1.x,
			data->args.player.hit1.y) != '1')
	{
		hypo[0] = (decimal.x + i) / cos(angle - M_PI);
		data->args.player.hit1.x = (int)data->args.player.pos.x - i;
		data->args.player.hit1.y = data->args.player.pos.y - sqrt(
				hypo[0] * hypo[0] - ((decimal.x + i) * (decimal.x + i)));
		i++;
	}
	hypo[1] = nw_x_1(data, decimal, angle);
	return (hypo);
}

double	nw_x_1(t_data *data, t_point decimal, double angle)
{
	int		i;
	double	hypo;

	i = 1;
	hypo = decimal.y / cos((M_PI / 2) - (angle - M_PI));
	data->args.player.hit2.x = data->args.player.pos.x - sqrt(hypo * hypo - (decimal.y * decimal.y));
	data->args.player.hit2.y = (int)data->args.player.pos.y;
	while (data->args.player.hit2.y >= 0 && data->args.player.hit2.x >= 0
		&& check_hit(data, 'n', data->args.player.hit2.x,
			data->args.player.hit2.y) != '1')
	{
		hypo = (decimal.y + i) / cos((M_PI / 2) - (angle - M_PI));
		data->args.player.hit2.x = data->args.player.pos.x - sqrt(
				hypo * hypo - ((decimal.y + i) * (decimal.y + i)));
		data->args.player.hit2.y = (int)data->args.player.pos.y - i;
		i++;
	}
	return (hypo);
}
