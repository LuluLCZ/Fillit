/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:42:25 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/16 22:09:42 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tetriminos.h"
#include "Libft/ft_strcat.c"
#include "ft_buf_to_tab.c"

static char		*ft_add_pt_tetrimino(char *tab)
{
	int		i;
	char	*new_str;
	int		k;

	k = 0;
	i = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * ft_strlen(tab) + 100)))
		return (NULL);
	if (ft_strcmp(tab, S8) == 0 || ft_strcmp(tab, S1) == 0|| 
			ft_strcmp(tab, S9) || ft_strcmp(tab, S18) == 0 || 
			ft_strcmp(tab, S16))
	{
		new_str[i] = '.';
		i++;
	}
	while (tab[k])
	{
		new_str[i] = tab[k];
		i++;
		k++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char		*ft_add_two_points(char *tab)
{
	int		i;
	char	*new_str;
	int		k;

	k = -1;
	i = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * ft_strlen(tab) + 100)))
		return (NULL);
	if (ft_strcmp(tab, S5) == 0)
	{
		while (i < 2)
		{
			new_str[i] = '.';
			i++;
		}
	}
	while (tab[k])
	{
		new_str[i] = tab[k++];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char		**ft_new_tab_wdots(char **tab)
{
	int		i;
	int		j;
	char	**new_tab;

	i = 0;
	j = 0;
	if (!(new_tab = (char **)malloc(sizeof(char *) * (27 * 25 + 1))))
		return (NULL);
	while (tab[j] != NULL)
	{
		new_tab[j] = ft_add_pt_tetrimino(tab[j]);
		new_tab[j] = ft_add_two_points(tab[j]);
		printf("%s\n", new_tab[j]);
		j++;
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
	new_ret = ft_split_dots(new_ret);
	//new_ret = ft_new_tab_wdots(new_ret);
	//ft_erreurs(new_ret);
	return (0);
}
