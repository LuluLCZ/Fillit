/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:22:40 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/13 12:30:47 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tetriminos.h"

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
	ft_erreurs(new_ret);
	//printf("%d", i);
	while (ret[index])
	{
		printf("%s\n", ret[index]);
		printf("%s\n", new_ret[index]);
		index++;
	}
	return (0);
}