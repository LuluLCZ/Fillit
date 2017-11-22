/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_positions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:58:52 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/16 17:41:49 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CheckMap/ft_tetriminos.h"
#include "ft_buf_to_tab.c"

static int		*ft_count_x(char *str)
{
	int		*x;
	int		i;
	int		count;
	int		index;

	*x = 0;
	index = 0;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (i == 4 || i == 8 || i == 12)
			count = 0;
		if (str[i] == '#')
		{
			x[index] = count;
			index++;
			//*x = 0;
		}
		i++;
		count++;
	}
	return (x);
}

static int		*ft_count_y(char *str)
{
	int		*y;
	int		i;
	int		count;
	int		index;

	i = 0;
	index = 0;
	count = 0;
	while (str[i])
	{
		if (i == 4 || i == 8 || i == 12)
			count++;
		if (str[i] == '#')
		{
			y[index] = count;
			index++;
		}
		i++;
	}
	return (y);
}

static void		ft_print_coord(char **tab)
{
	int		*x;
	int		*y;
	int		index;
	int		j;

	x = ft_count_x(tab[j]);
	y = ft_count_y(tab[j]);
	index = 0;
//	while (tab[j])
//	{

		while (index < 4)
		{
			//printf("%d\n", y[index]);
			printf("[%d]:\n", x[index]);
			index++;
		}
//		index = 0;
//		j++;
//	}
}

int		main(int ac, char **av)
{
	(void)ac;
	int		fd;
	int		j;
	char	**tab;
	//int		*x;
	int		index;

	index = 0;
	j = 0;
	fd = open(av[1], O_RDONLY);
	tab = ft_str_split_nl(ft_str_to_tab(ft_buf_to_str(fd)));
	//printf("%s", tab[j]);
	ft_print_coord(tab);
	//x = ft_count_x(tab[j]);
/*	while (tab[index])
	{
		printf("%s\n", tab[index]);
		index++;;
	}*/
	return (0);
}
