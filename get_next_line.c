/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:21:33 by amandine          #+#    #+#             */
/*   Updated: 2025/06/24 14:28:27 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen((char *)s1) + ft_strlen((char *)s2)
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
	return (str);
}

char *get_next_line(int fd);
{
    int i;
    size_t count;
    size_t octet_buf;
    static char *buffer;
    char *tmp;
    char *line;

    i = 0;
    count = 16;
    line = malloc(sizeof(char) * 1)
        if(!line)
            return (NULL);
    line[o] = '\0';
    octet_buf = read(fd, (void)*buffer, count);
    buffer[octet_buf] = '\0';
    tmp = ft_strdup((const char)*buffer);
    while (octet_buf > 0)
        buffer[octet_buf--] = '\0';
    buffer[octet_buf] = '\0';
    while (tmp[i] != '\0')
    {
        if (tmp[i] == '\n')
        {
            i++;
            while (tmp[i] != '\0')
            {
                buffer[octet_buf] = tmp[i];
                tmp[i] = '\0';
                i++;
            } 
            line = ft_strjoin((char const)*line, (char const)*tmp);
            return (line);
        }
        i++;
    }
    line = ft_strjoin((char const)*line, (char const)*tmp);
    
}

// ssize_t read(int fd, void *buf, size_t count)
// ---------------------
// Écrire une fonction qui retourne 
// une ligne lue depuis un descripteur de fichier
// ---------------------
// Desappels successifs à votre fonction get_next_line() 
// doivent vous permettre de lire l’intégralité du fichier 
// texte référencé par le descripteur de fichier, 
// une ligne à la fois.
// ---------------------
// S’il n’y a plus rien à lire, ou en cas d’erreur, 
// elle doit retourner NULL.
// ---------------------
// retourner la ligne qui a été lue suivie du \n la terminant,
// sauf dans le cas où vous avez atteint la fin du fichier et 
// que ce dernier ne se termine pas par un \n.
// ---------------------
// Votre programme doit compiler avec l’option :-D BUFFER_SIZE=n
// ---------------------
// Cette macro définie à l’invocation du compilateur servira 
// à spécifier la taille du buffer lors de vos appels à read() 
// dans votre fonction get_next_line(). Cette valeur sera modifiée lors de la peer-evaluation et 
// par la Moulinette dans le but de tester votre rendu
// ---------------------
// cc-Wall-Wextra-Werror-D BUFFER_SIZE=42 <files>.c
// ---------------------
// Les variables globales sont interdites
// ---------------------
// ---------------------