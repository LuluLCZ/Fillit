/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_toutsplit3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:14:32 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/10 14:16:17 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_tetriminos.h>
#include "ft_test_tout3.c"

static char		**ft_test_toutsplit3(char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[j][i] != '\n' && tab[j][i] != '\0')
	{
		i++;
		if (tab[j][i] == '\n')
	}
}
