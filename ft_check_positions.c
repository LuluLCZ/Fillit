/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_positions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:58:52 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/14 19:18:44 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CheckMap/ft_tetriminos.h"
#include "ft_buf_to_tab.c"

static int		*ft_count_x(char *str)
{
	int		*x;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	x[k] = 0;
	while (str[i] && k < 4)
	{
		if (i == 4 || i == 8 || i == 12)
			j = 0;
		if (str[i] == '#')
		{
			write(1, "p", 1);
			x[k] = j;
			k++;
		}
		i++;
		j++;
	}
	return (x);
}

int		main(int ac, char **av)
{
	(void)ac;
	int		fd;
	int		j;
	char	**tab;
	int		*x;
	int		index;

	index = 0;
	j = 0;
	fd = open(av[1], O_RDONLY);
	tab = ft_str_to_tab(ft_buf_to_str(fd));
	x = ft_count_x(tab[j]);
	while (x[index] && index < 4)
	{
		write(1, "c", 1);
		printf("%d\n", x[index]);
		index++;;
	}
	return (0);
}
