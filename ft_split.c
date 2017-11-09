/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:24:52 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/09 20:19:45 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.c"

static char		*ft_split(char *str)
{
	int		i;
	char	*new_str;
	int		j;

	i = 0;
	j = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * 50000)))
		return (NULL);
	while (str[i])
	{
		new_str[j] = str[i];
		i++;
		j++;
		if (i == 4 || i == 8 || i == 12 || i == 16)
		{
			new_str[j] = '\n';
			j++;
		}
	}
	while (j < 19)
	{
		if (j == 4 || j == 9 || j == 14 || j == 19)
		{
			new_str[j] = '\n';
			j++;
		}
		new_str[j] = '.';
		j++;
	}
	return (new_str);
}
