/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:52:27 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/11 20:27:03 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tetriminos.h"

static int		ft_check_valide(char *str)
{
	int		i;

	i = 0;
	(ft_strcmp(str, S1)) == 0 ? i++ : i;
	(ft_strcmp(str, S2)) == 0 ? i++ : i;
	(ft_strcmp(str, S3))== 0 ? i++ : i;
	(ft_strcmp(str, S4)) == 0 ? i++ : i;
	(ft_strcmp(str, S5)) == 0 ? i++ : i;
	(ft_strcmp(str, S6)) == 0 ? i++ : i;
	(ft_strcmp(str, S7)) == 0 ? i++ : i;
	(ft_strcmp(str, S8)) == 0 ? i++ : i;
	(ft_strcmp(str, S9)) == 0 ? i++ : i;
	(ft_strcmp(str, S10)) == 0 ? i++ : i;
	(ft_strcmp(str, S11)) == 0 ? i++ : i;
	(ft_strcmp(str, S12)) == 0 ? i++ : i;
	(ft_strcmp(str, S13)) == 0 ? i++ : i;
	return (i);
}

static int		check_tetriminos(char *str)
{
	int i;
	int newline;
	int sharp;

	i = 0;
	newline = 0;
	sharp = 0;
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
	{
		write(1, "Map non valde", 15);
		exit(EXIT_FAILURE);
	}
	while (i <= 19)
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (0);
		if (str[i] == '\n')
			newline++;
		if (str[i] == '#')
			sharp++;
		i++;
		write(1, "r", 1);
	}
	if (newline == 4 && sharp == 4 && str[19] == '\n' && !str[20])
		return (1);
	write(1, "Mou", 3);
	exit(EXIT_FAILURE);
	return (0);
}

static int		ft_tab_check_tetri(char **tab)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (tab[j])
	{

		write(1, "p", 1);
		i = check_tetriminos(tab[j]);
		write(1, "q", 1);
		if (i == 1)
		{
			write(1, "Map valide\n", 11);
			j++;
		}
		else
		{
			write(1, "Tetrimino non valide\n", 21);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}

static void		ft_erreurs(char **tab)
{
	int		j;
	int		count;

	count = 0;
	j = 0;
	while (tab[j])
	{
		count = ft_check_valide(tab[j]);
		if (count == 1)
		{
			write(1, "Tetrimino valide\n", 17);
			j++;
		}
		else
		{
			write(1, "Tetrimino non valide", 20);
			j++;
		}
	}
}
