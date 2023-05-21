/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <ojauregu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:57:44 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/14 15:39:33 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	print_error(char *msg)
{
	ft_putstr_fd(STDERR_FILENO, RED);
	ft_putstr_fd(STDERR_FILENO, "Error :\n ");
	ft_putstr_fd(STDERR_FILENO, msg);
	ft_putstr_fd(STDERR_FILENO, NRM);
	write(STDERR_FILENO, "\n", 1);
	return (ERROR);
}

char	*print_error_null(char *msg)
{
	ft_putstr_fd(STDERR_FILENO, RED);
	ft_putstr_fd(STDERR_FILENO, "Error :\n ");
	ft_putstr_fd(STDERR_FILENO, msg);
	ft_putstr_fd(STDERR_FILENO, NRM);
	write(STDERR_FILENO, "\n", 1);
	return (NULL);
}

int	print_error_to_free(char *msg)
{
	ft_putstr_fd(STDERR_FILENO, RED);
	ft_putstr_fd(STDERR_FILENO, "Error :\n ");
	ft_putstr_fd(STDERR_FILENO, msg);
	ft_putstr_fd(STDERR_FILENO, NRM);
	write(STDERR_FILENO, "\n", 1);
	free(msg);
	return (ERROR_BIS);
}

void	free_error(t_data *data, char *msg)
{
	if (data->file.textures.north)
		free(data->file.textures.north);
	if (data->file.textures.south)
		free(data->file.textures.south);
	if (data->file.textures.east)
		free(data->file.textures.east);
	if (data->file.textures.west)
		free(data->file.textures.west);
	print_error(msg);
	exit(1);
}

int	petf(char *msg)
{
	ft_putstr_fd(STDERR_FILENO, RED);
	ft_putstr_fd(STDERR_FILENO, "Error :\n ");
	ft_putstr_fd(STDERR_FILENO, msg);
	ft_putstr_fd(STDERR_FILENO, NRM);
	write(STDERR_FILENO, "\n", 1);
	free(msg);
	return (ERROR);
}
