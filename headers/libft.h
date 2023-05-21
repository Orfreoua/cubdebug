/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <ojauregu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:57:51 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/21 04:05:06 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "headers.h"

void	ft_putstr_fd(int fd, char *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
int     ft_strncmp(char *str1, char *str2, int n);
char	*ft_substr(char *s, int x, int y);
char	*ft_strjoin(char const *s1, char const *s2, int index_free);
char	*ft_strdup(const char *s);

#endif