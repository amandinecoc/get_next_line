/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:42:33 by acocoual          #+#    #+#             */
/*   Updated: 2025/06/26 13:30:03 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main()
{
    int fd = open("./fichier.txt", O_RDONLY);
	char *line;
    
    line =  get_next_line_bonus("-1");
    while (line != NULL)
    {
        printf("%s", line);
        free(line);
        line = get_next_line_bonus("-1");
    }
    free(line);
    close(fd);
	return (0);
}
