/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:54:08 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/16 21:22:19 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CheckMap/ft_tetriminos.h"
#include "CheckMap/ft_modif_point.c"

static char		*ft_copy_to_one(char *str)
{
	int		i;
	//int		j;
	//int		k;
	int		l;
	int		m;
	char	*new_tab;

	i = 0;
	//j = 0;
	//k = 0;
	l = 0;
	m = 0;
	if (!(new_tab = (char *)malloc(sizeof(char) * (27 * 25 + 1))))
		return (NULL);
	while (str[i] != '.')
	{
		write(1, "a", 1);
		new_tab[l] = str[i];
		write(1, "b", 1);
		l++;
		i++;
	}
	while ([i] == '.')
	{
		new_tab[k][l] = tab[j + 1][m];
		l++;
		m++;
		while (tab[j][i] != '.')
		{
			new_tab[k][l] = tab[j][i];
			l++;
			i++;
		}
	}
	return (new_tab);
}

static char		**ft_solve(char **tab)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char **new_tab;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (tab)
	{
		new_tab = ft_copy_to_one(tab, j, k);
		j++;
		k++;
	}
	return (new_tab);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	char	**ret;
	char	**new_ret;
	//char	*str;
	int		fd;
	int		index;
	int		i;
	int		j;

	j = 0;
	i = 0;
	index = 0;
	fd = open(av[1], O_RDONLY);
	//str = ft_buf_to_str(fd);
	ret = ft_str_to_tab(ft_buf_to_str(fd));
	i = ft_tab_check_tetri(ret);
	if (i != 1)
	{
		write(1, "a", 1);
		exit(EXIT_FAILURE);
	}
	new_ret = ft_str_split_nl(ret);
	//write(1, "b", 1);
	new_ret = ft_split_dots(new_ret);
	//write(1, "s", 1);
	ft_erreurs(new_ret);
	//write(1, "p", 1);
	new_ret = ft_new_tab_wdots(new_ret);
	//write(1, "2", 1);
	new_ret = ft_solve(new_ret);
	return (0);
}
