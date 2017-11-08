/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erreurs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:37:38 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/08 18:01:34 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.c"

/* On va gerer dans ce fichiers les differents cas d'erreurs posible
 * premierement on va ouvrir le fichier (open <fcntl.h>) puis le parcourir
 * a l'aide de la fonction read (unistd.h).
 * On sait que chaque tetrimino doit resider dans un carre dans 4*4 points.
 * + un '\n'. On sait aussi que chaque tertrimino est au maximum compose de
 * 4 cubes. On va faire ligne par ligne donc a arriver jusqu'au '\n'
 * il faut qu'il ai un compteur de points et un compteur de dieses.
 * arrive au bout de la ligne on a un compteur qui va permettre nous permettre
 * a la fin du carre a savoir premierement si il y a le nombre de dieses et de
 * points qu'il faut en soustrayant 4 (le nombre de cube dans un tetrimino)
 * a 16 (le nombre de point, case disponibles de base)
 * */

static int		ft_count_place(int fd)
{
	int		count_point;
	int		count_hash;
	int		count_char;
	int		nl;
//	int		lines;
	int		i;
	int		result;
	char	buf;

	nl = 0;
	result = 0;
	i = 0;
	count_char = 0;
	count_point = 0;
	count_hash = 0;
	while (read(fd, &buf, 1) != 0)
	{
		if (buf == '.')
		{
			count_point++;
			write(1, "a", 1);
		}
		if (buf == '#')
		{
			count_hash++;
			write(1, "b", 1);
		}
		if (buf == '\n')
			nl++;
		count_char++;
	}
//	if (read(fd, &buf, 1) == 0)
//	{
	result = count_point + count_hash;
//		write(1, "c", 1);
//	}
	printf("%d", result);
	if (result != 16)
		write(2, "error", 6);
	//else
	/* Ici j'aimerai faire une recursive de cette fonction tant que lines
		 * != 4 pour pouvoir le faire sur chaque ligne d'un tetrimino;
		 * */
	return (count_char);
}
