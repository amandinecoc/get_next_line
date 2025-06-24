/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:21:33 by amandine          #+#    #+#             */
/*   Updated: 2025/06/24 09:33:41 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd);
{
    
}
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