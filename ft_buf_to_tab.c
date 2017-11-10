/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_tout3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:23:12 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/10 17:30:18 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tetriminos.h"
#include "../../Projets/Libft/ft_strcmp.c"
#include "ft_strsplit_fillit.c"
#include "ft_strtrimfillit.c"

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

/* On va utiliser ca pour savoir si c'est un tetrimino valide avant tout, 
 * pour plus tard;
char	*ft_str_cmp(char **tab)
{
	int		i;

	i = 0;
	if (ft_strcmp(tab[i], S1) == 0)
		return (tab[i]);
	write(2, "erreur", 7);
	return (NULL);
}
*/

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
	if (!(new_tab = (char **)malloc(sizeof(char *) * 21)))
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
			if (tab[j][i] == '\n')
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

	index = 0;
	fd = open(av[1], O_RDONLY);
	ret = ft_str_to_tab(ft_buf_to_str(fd));
	new_ret = ft_str_split_nl(ret);
	while (ret[index])
	{
		printf("%s\n", new_ret[index]);
		index++;
	}
	return (0);
}
