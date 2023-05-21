/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <ojauregu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:05:36 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/14 17:49:54 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

int	check_file(char *file)
{
	int	len_name;
	int	fd;

	len_name = ft_strlen(file);
	if (!len_name)
		return (print_error(EMPTY_ARG_FILE));
	if (file[0] == '.')
		return (print_error(SECRET_FILE));
	if (file[len_name - 4] != '.' || file[len_name - 3] != 'c'
		|| file[len_name - 2] != 'u' || file[len_name - 1] != 'b')
		return (print_error(BAD_NAME_FILE));
	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (print_error(PATH_IS_DIR));
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_error(BAD_PATH_FILE));
	close(fd);
	return (OK);
}

void	load_path(t_data *data, char *line, char **path, int fd)
{
	if (*path)
	{
		printf("%s\n", *path);
		free(line);
		close(fd);
		free_error(data, DOUBLE_SAME_PATH);
	}
}

int	check_inside_file(t_data *data, int fd)
{
	char	*line;
	int		nb;

	nb = 0;
	if (fd == -1)
		return (print_error(BAD_PATH_FILE));
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strncmp(line, "NO ", 3))
			load_path(data, line, &data->file.textures.north, fd);
		else if (ft_strncmp(line, "SO ", 3))
			load_path(data, line, &data->file.textures.south, fd);
		else if (ft_strncmp(line, "EA ", 3))
			load_path(data, line, &data->file.textures.east, fd);
		else if (ft_strncmp(line, "WE ", 3))
			load_path(data, line, &data->file.textures.west, fd);
		else
			break ;
		nb++;
		if (all_data_is_recovered(data))
			break ;
	}
	return (OK);
}

int	load_file(t_data *data, char *file)
{
	if (check_file(file) == ERROR)
		return (ERROR);
	init_file(&data->file);
	if (parsing_map(data, file) == ERROR)
		return (ERROR);
	if (data->file.map[0][0] == -1)
	{
		data->file.parsing_map_msg = NO_MAP;
		pars_error(-1, data);
		free_all(data);
		return (ERROR);
	}
	else if (check_map(data) == -1)
	{
		pars_error(-1, data);
		free_all(data);
		return (ERROR);
	}
	data->file.mapy = last_for_screen(data, 0, 0);
	return (OK);
}
