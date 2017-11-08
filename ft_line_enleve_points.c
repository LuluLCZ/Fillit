/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_enleve_points.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:13:05 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/08 18:38:24 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.c"
#include "ft_erreurs.c"
#include "ft_buf_to_str.c"
/* Ici on va apres avoir, mis la verifier que la map est bonne et qu'elle est 
 * en ligne, virer les points du debut pour pouvoir trouver quel tetrimino
 * est present car une fois les premiers points virer les ecarts entre les 
 * dieses sont tous les memes
*/

static	int		ft_count_place(int fd);

static	char	*ft_strsplit_nl(int fd);

static char		*ft_remove_points(int fd)
{
	char	*str;
	int		i;
	char	*new_str;
	int		count_hash;
	int		j;

	j = 0;
	count_hash = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * (ft_count_place(fd) + 1))))
			return (NULL);
	i = 0;
	str = ft_strsplit_nl(fd);
	while (str[i] == '.')
		i++;
	while (count_hash <= 4)
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	return (new_str);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	int		fd;

	fd = open(av[1], O_RDONLY);
	ft_remove_points(fd);
	close(fd);
	return (0);
}
