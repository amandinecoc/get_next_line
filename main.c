/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:42:33 by acocoual          #+#    #+#             */
/*   Updated: 2025/06/30 00:12:55 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
    int fd = open("./fichier.txt", O_RDONLY);
	char *line;
    int i = 1;
    line =  get_next_line(fd);
    while (line != NULL)
    {
        printf("%d =%s", i, line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    free(line);
    line = get_next_line(fd);
    printf("%d =%s", i, line);
    free(line);
    close(fd);
	return (0);
}
