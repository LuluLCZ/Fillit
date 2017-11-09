/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriminos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:59:50 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/09 19:22:06 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.c"
#include "../Libft/ft_strcmp.c"
#include "ft_tetriminos.h"

static char		*ft_tetriminos1(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * 500)))
		return (NULL);
	if (ft_strcmp(str, S1) == 0)
	{
		new_str[0] = '.';
		i = 1;
		while (str[j])
		{
			new_str[i] = str[j];
			i++;
			j++;
		}
		new_str[i] = '\0';
	}
	else
		write(1, "b", 1);
	return (new_str);
}

static char		*ft_tetriminos2(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * 500)))
		return (NULL);
	if (ft_strcmp(str, S5) == 0)
	{
		while (i != 2)
		{
			new_str[i] = '.';
			i++;
		}
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

static char		*ft_tetriminos3(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * 500)))
		return (NULL);
	if (ft_strcmp(str, S8) == 0)
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

static char		*ft_tetriminos4(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * 500)))
		return (NULL);
	if (ft_strcmp(str, S9) == 0)
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

static char		*ft_test_tetri(char *str)
{
	if (ft_strcmp(str, S1) == 0)
		str = ft_tetriminos1(str);
	else if (ft_strcmp(str, S5) == 0)
		str = ft_tetriminos2(str);
	else if (ft_strcmp(str, S8) == 0)
		str = ft_tetriminos3(str);
	else if (ft_strcmp(str, S9) == 0)
		str = ft_tetriminos4(str);
	return (str);
}
