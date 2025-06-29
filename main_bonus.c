/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:42:33 by acocoual          #+#    #+#             */
/*   Updated: 2025/06/29 16:21:12 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main()
{
    int fd1 = open("./fichier.txt", O_RDONLY);
    int fd2 = open("./fichier2.txt", O_RDONLY);
    
    printf("%s", get_next_line_bonus(-2));
    // printf("%s", get_next_line_bonus(0));
    // printf("%s", get_next_line_bonus(1));
    // printf("%s", get_next_line_bonus(2));
    printf("%s", get_next_line_bonus(fd1));
    printf("%s", get_next_line_bonus(fd2));
    printf("%s", get_next_line_bonus(fd1));
    printf("%s", get_next_line_bonus(fd2));
    printf("%s", get_next_line_bonus(fd2));
    close(fd1);
    close(fd2);
	return (0);
}
