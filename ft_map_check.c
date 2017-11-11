/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:43:45 by ddombya           #+#    #+#             */
/*   Updated: 2017/11/11 17:57:10 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tetriminos.h"

static int		check_tetriminos(char *str)
{
	int i;
	int newline;
	int sharp;

	i = 0;
	newline = 0;
	sharp = 0;
	if (!str || !*str || str[4] != '\n' || str[9] != '\n' || str[14] != '\n'
			|| str[19] != '\n' || str[24] != '\n')
		write(2, "erreur", 7);
	while (i <= 19)
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (0);
		if (str[i] == '\n')
			newline++;
		if (str[i] == '#')
			sharp++;
	}
	/*if (newline == 4 && sharp == 4 && str[19] == '\n' && str[20] != '\n')
		return (check_tetriminos(str));*/
	if (newline == 4 && sharp == 4 && str[19] == '\n' && !str[21])
		return (1);
	return (0);
}
