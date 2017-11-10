/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 08:26:00 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/10 16:34:51 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_tetriminos.h"
#include "../Libft/ft_strsub.c"

size_t	 ft_strlen(char const *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strsplit(char const *s, char c)
{
	char		*str;
	size_t		i;
	size_t		j;
	int			start;
	int			end;
	int			k;

	k = 0;
	str = NULL;
	j = 0;
	i = 0;
	if (s && (str = (char *)malloc(sizeof(char) * ft_strlen(s))))
	{
		while (s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			start = i;
			while (s[i])
				i++;
			while (s[i] != c)
				i--;
			end = i;
			if (end > start)
				str = ft_strsub(s, start, (end - start));
		}
		str[end - start + 1] = '\0';
	}
	return (str);
}
