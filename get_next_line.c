/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:21:33 by amandine          #+#    #+#             */
/*   Updated: 2025/07/31 16:06:57 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_n_in_remaining_line(char **line, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while ((*line)[i] != '\0')
	{
		if ((*line)[i] == '\n')
		{
			i++;
			j = 0;
			while ((*line)[i] != '\0')
			{
				buffer[j++] = (*line)[i];
				(*line)[i++] = '\0';
			}
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_FAILURE);
}

int	check_n_in_next_line(char **line, char *buffer, int fd, int len_buf)
{
	int		i;
	char	*tmp;

	while (len_buf > 0)
	{
		i = 0;
		len_buf = read(fd, buffer, BUFFER_SIZE);
		if (len_buf < 0)
			return (EXIT_FAILURE);
		buffer[len_buf] = '\0';
		tmp = ft_strdup(buffer);
		ft_bzero(buffer, len_buf);
		while (tmp[i] != '\0')
		{
			if (tmp[i] == '\n')
			{
				*line = fill_remain_in_buffer(i, &tmp, buffer, *line);
				return (EXIT_SUCCESS);
			}
			i++;
		}
		*line = ft_strjoin(*line, tmp);
	}
	return (EXIT_FAILURE);
}

char	*fill_remain_in_buffer(int i, char **tmp, char *buffer, char *line)
{
	int	j;

	j = 0;
	i++;
	while ((*tmp)[i] != '\0')
	{
		buffer[j++] = (*tmp)[i];
		(*tmp)[i++] = '\0';
	}
	line = ft_strjoin(line, *tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	int			size;
	int			len_buf;
	static char	buffer[BUFFER_SIZE];
	char		*line;

	if (fd < 0)
		return (ft_bzero(buffer, BUFFER_SIZE), NULL);
	len_buf = BUFFER_SIZE;
	line = ft_strdup(buffer);
	ft_bzero(buffer, len_buf);
	if (check_n_in_remaining_line(&line, buffer) == EXIT_SUCCESS)
		return (line);
	if (check_n_in_next_line(&line, buffer, fd, len_buf) == EXIT_SUCCESS)
		return (line);
	size = ft_strlen(line);
	if (size > 0)
		return (line);
	return (ft_bzero(buffer, BUFFER_SIZE), free((void *)line), NULL);
}
