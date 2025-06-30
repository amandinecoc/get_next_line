/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:21:33 by amandine          #+#    #+#             */
/*   Updated: 2025/06/30 17:19:49 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;
	int			j;
	int			len_buf;
	static char	buffer[BUFFER_SIZE];
	char		*tmp;
	char		*line;

	if (fd < 0)
		return (ft_bzero(buffer, BUFFER_SIZE), NULL);
	len_buf = BUFFER_SIZE;
	line = ft_strdup(buffer);
	ft_bzero(buffer, len_buf);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			i++;
			j = 0;
			while (line[i] != '\0')
			{
				buffer[j] = line[i];
				line[i] = '\0';
				i++;
				j++;
			}
			return (line);
		}
		i++;
	}
	while (len_buf > 0)
	{
		i = 0;
		len_buf = read(fd, buffer, BUFFER_SIZE);
		buffer[len_buf] = '\0';
		tmp = ft_strdup(buffer);
		ft_bzero(buffer, len_buf);
		while (tmp[i] != '\0')
		{
			if (tmp[i] == '\n')
			{
				i++;
				j = 0;
				while (tmp[i] != '\0')
				{
					buffer[j] = tmp[i];
					tmp[i] = '\0';
					i++;
					j++;
				}
				// buffer[j] = '\0';
				line = ft_strjoin(line, tmp);
				return (line);
			}
			i++;
		}
		line = ft_strjoin(line, tmp);
	}
	j = ft_strlen(line);
	if (j > 0)
		return (line);
	return (ft_bzero(buffer, BUFFER_SIZE), free((void *)line), NULL);
}
