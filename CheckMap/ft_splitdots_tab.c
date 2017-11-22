/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdots_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:00:39 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/16 22:18:55 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tetriminos.h"

static int		ft_end_sharp(char *tab)
{
	int		sharp;
	int		i;

	sharp = 0;
	i = 0;
	while (tab[i] != '#' && tab[i])
		i++;
	while (tab[i])
	{
		if (tab[i] == '#')
			sharp++;
		if (sharp == 4)
			return (i);
		i++;
	}
	return (0);
}

static char		**ft_split_dots(char **tab)
{
	char	**new_tab;
	int		i;
	int		j;
	size_t		start;

	j = 0;
	i = 0;
	start = 0;
	if (!(new_tab = (char **)malloc(sizeof(char *) * (27 * 25 + 1))))
		return (NULL);
	while (tab[j])
	{
		while (tab[j][i] != '#' && tab[j][i])
			i++;
		start = i;
		new_tab[j] = ft_strsub(tab[j], start, ft_end_sharp(tab[j]) - start + 1);
		printf("%s", new_tab[j]);
		j++;
		i = 0;
	}
	return (new_tab);
}
