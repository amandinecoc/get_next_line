/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:42:33 by acocoual          #+#    #+#             */
/*   Updated: 2025/06/26 13:20:04 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
    int fd = open("./fichier.txt", O_RDONLY);
	char *line;
    
    line =  get_next_line("-1");
    while (line != NULL)
    {
        printf("%s", line);
        free(line);
        line = get_next_line("-1");
    }
    free(line);
    close(fd);
	return (0);
}
