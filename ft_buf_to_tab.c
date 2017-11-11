/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:23:12 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/11 20:26:51 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tetriminos.h"
#include "../../Projets/Libft/ft_strcmp.c"
#include "../../Projets/Libft/ft_strsub.c"
#include "../../Projets/Libft/ft_strlen.c"
#include "ft_splitdots_tab.c"
#include "ft_check_tetri.c"

static int		ft_check_valide(char *str);

static void		ft_erreurs(char **tab);

static int		check_tetriminos(char *str);

static int		ft_end_sharp(char *tab);

static char		**ft_split_dots(char **tab);

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
	size_t			count;
	char		**new_str;

	count = 0;
	i = 0;
	k = 0;
	j = 0;
	if (!(new_str = (char **)malloc(sizeof(char *) * 22)))
		return (NULL);
	while (i < ft_strlen(str))
	{
		if (i == 0)
		{
			count = 20;
			//printf("%s", str);
			new_str[j] = ft_strsub(str, i, count);
			printf("%s", new_str[j]);
			count = 0;
			j = 1;
		}
		if (count == 20)
		{
			new_str[j++] = ft_strsub(str, i++ - count, count);
			count = 0;
			printf("%s", new_str[j]);
	//		write(1, "a", 1);
		}
		i++;
		count++;
	}
	//printf("%d", count);
	return (new_str);
}

static char		**ft_str_split_nl(char **tab)
{
	char	**new_tab;
	char	*str;
	size_t		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	if (!(str = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	if (!(new_tab = (char **)malloc(sizeof(char *) * 50)))
		return (NULL);
	while (tab[j])
	{
		i = 0;
		k = 0;
		while (tab[j][i] != '\n' && tab[j][i] != '\0')
		{
			str[k] = tab[j][i];
			i++;
			k++;
			while (tab[j][i] == '\n' && tab[j][i])
				i++;
		}
		new_tab[j++] = ft_strsub(str, 0, ft_strlen(str));
	}
	return (new_tab);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	char	**ret;
	char	**new_ret;
	int		fd;
	int		index;
	int		i;

	i = 0;
	index = 0;
	fd = open(av[1], O_RDONLY);
	ret = ft_str_to_tab(ft_buf_to_str(fd));
	i = ft_tab_check_tetri(ret);
	if (i == 0)
	{
		write(1, "a", 1);
		exit(EXIT_FAILURE);
	}
	new_ret = ft_str_split_nl(ret);
	new_ret = ft_split_dots(new_ret);
	ft_erreurs(new_ret);
	while (ret[index])
	{
		printf("%s", ret[index]);
		//printf("%s\n", new_ret[index]);
		index++;
	}
	return (0);
}
