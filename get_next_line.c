/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:21:33 by amandine          #+#    #+#             */
/*   Updated: 2025/06/25 17:19:58 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
				+ 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (free((void *)s1), free((void *)s2), str);
}

void	ft_bzero(void *s, size_t n)
{
	char	*tmp_s;

	tmp_s = (char *)s;
	while (n > 0)
	{
		*tmp_s = 0;
		tmp_s++;
		n--;
	}
}

char	*get_next_line(int fd)
{
	int i;
	int j;
	int len_buf;
	static char buffer[BUFFER_SIZE];
	char *tmp;
	char *line;

    if (fd < 0)
    {
        return (NULL);
    }
	len_buf = BUFFER_SIZE;
	line = ft_strdup(buffer);
    ft_bzero(buffer, len_buf);
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
	return (free((void*)line), NULL);
}

int	main()
{
    int fd = open("./fichier.txt", O_RDONLY);
	char *line;
    
    line =  get_next_line(fd);
    while (line != NULL)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
	return (0);
}
