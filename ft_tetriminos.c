/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriminos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:59:50 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/09 18:17:10 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.c"
#include "../Libft/ft_strcmp.c"
#include "ft_tetriminos.h"

static char		*ft_tetriminos(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * 50)))
		return (NULL);
	if (ft_strcmp(str, S1) == 0)
	{
		new_str[i] = '.';
		i++;
		while (str[j])
		{
			new_str[i] = str[j];
			i++;
			j++;
		}
	}
	else
		write(1, "a", 1);
	return (new_str);
}
