/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_tout3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:23:12 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/10 13:31:54 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tetriminos.h"
#include "../../Projets/Libft/ft_strsub.c"
#include "../../Projets/Libft/ft_strlen.c"
#include "../../Projets/Libft/ft_strcmp.c"

static char		*ft_buf_to_str(int fd)
{
	char	buf;
	int		i;
	char	*str;
	int		reead;

	i = 0;
	reead = read(fd, &buf, 1);
	if (!(str = (char *)malloc(sizeof(char) * 500)))
		return (NULL);
	while (reead == 1 && buf != '\0')
	{
		str[i] = buf;
		i++;
		reead = read(fd, &buf, 1);
	}
	str[i] = '\0';
	return (str);
}

static char		**ft_str_to_tab(char *str)
{
	size_t		i;
	size_t		j;
	size_t		k;
	int			count;
	char		**new_str;

	count = 0;
	i = 0;
	k = 0;
	j = 0;
	if (!(new_str = (char **)malloc(sizeof(char *) * 21)))
		return (NULL);
	while (i < ft_strlen(str))
	{
		if (count == 20)
		{
			new_str[j++] = ft_strsub(str, i++ - count, count + 1);
			count = 0;
	//		write(1, "a", 1);
		}
		i++;
		count++;
	}
	new_str[j] = NULL;
	//printf("%d", count);
	return (new_str);
}

char	*ft_str_cmp(char **tab)
{
	int		i;

	i = 0;
	if (ft_strcmp(tab[i], S1) == 0)
		return (tab[i]);
	write(2, "erreur", 7);
	return (NULL);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	char	**ret;
	char	*new_ret;
	int		fd;
	int		index;

	index = 0;
	fd = open(av[1], O_RDONLY);
	ret = ft_str_to_tab(ft_buf_to_str(fd));
	new_ret = ft_str_cmp(ret);
	printf("%s", new_ret);
	return (0);
}
