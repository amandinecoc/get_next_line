/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:42:33 by acocoual          #+#    #+#             */
/*   Updated: 2025/07/01 13:30:43 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	int	fd1;
	int	fd2;

	fd1 = open("./fichier.txt", O_RDONLY);
	fd2 = open("./fichier2.txt", O_RDONLY);
	printf("%s", get_next_line(-2));
	// printf("%s", get_next_line(0));
	// printf("%s", get_next_line(1));
	// printf("%s", get_next_line(2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	close(fd1);
	close(fd2);
	return (0);
}
