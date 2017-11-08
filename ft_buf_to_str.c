/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:16:37 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/08 18:40:54 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.c"

/* On va copier le buf dans une string en enlevant les '\n' pour pouvoir tout
 * lire en une seule ligne et reussir a determiner la forme du tetrimino
 */
//compter le nombre de '\n' pour compter la taille a malloc dans le str
//car il y aura 4 '\n' par tetriminos donc pour deux tetriminos on aura
//8 '\n' et 1 '\0' donc deux tetriminos mais ce n est seulement a faire quand
//on a fait passer le ft_erreur dessus pour savoir si la map est bonne pour 
//ne pas allouer de la memoire pour rien

static int		ft_count_place(int fd);

static char		*ft_copy_bufstr(int fd)
{
	char	buf;
	char	*str;
	int		i;
	int		count_char;

	count_char = ft_count_place(fd);
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * count_char + 1)))
		return (NULL);
	while (read(fd, &buf, 1) != 0)
		str[i] = buf;
	str[i] = '\0';
	return (str);
}

static char		*ft_strsplit_nl(int fd)
{
	char	*str;
	char	*new_str;
	int		i;
	//int		count_char;

	str = ft_copy_bufstr(fd);
	i = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * ft_count_place(fd))))
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
		while (str[i] == '\n')
			i++;
	}
	return (new_str);
}
