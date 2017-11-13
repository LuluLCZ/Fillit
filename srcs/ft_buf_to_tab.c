/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:23:12 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/13 12:32:41 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tetriminos.h"
#include "../Libft/ft_strcmp.c"
#include "../Libft/ft_strsub.c"
#include "../Libft/ft_strlen.c"
#include "ft_splitdots_tab.c"
#include "ft_check_tetri.c"
#include "../../Projets/Libft/ft_strnew.c"
#include "main.c"

/*static int		ft_check_valide(char *str);

static void		ft_erreurs(char **tab);

static int		check_tetriminos(char *str);

static int		ft_end_sharp(char *tab);

static char		**ft_split_dots(char **tab);
*/
static char		*ft_buf_to_str(int fd)
{
	char	buf;
	int		i;
	char	*str;
	int		reead;

	i = 0;
	reead = read(fd, &buf, 1);
	if (!(str = (char *)malloc(sizeof(char) * (21 * 26 + 1))))
		return (NULL);
	while (reead == 1 && buf != '\0')
	{
	//if (!(str = (char *)malloc(sizeof(char) * i)))
	//	return (NULL);
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
	char		**new_str;

	i = 0;
	k = 0;
	j = 0;
	if (str[ft_strlen(str) - 2] != '#' && str[ft_strlen(str) - 2] != '.')
	{
		write(1, "Erreur de map", 13);
		exit(EXIT_FAILURE);
	}
	if (!(new_str = (char **)malloc(sizeof(char *) * (ft_strlen(str)))))
		return (NULL);
	while (str[i])
	{
		new_str[j] = ft_strsub(str, i, 20);
		j++;
		i = i + 21;
	}
	if (j > 26)
	{
		write(1, "Trop de tetriminos", 19);
		exit(EXIT_FAILURE);
	}
	new_str[j] = NULL;
	free(str);
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
	if (!(str = (char *)malloc(sizeof(char) * 50)))
		return (NULL);
	if (!(new_tab = (char **)malloc(sizeof(char *) * ft_strlen(str) + (26 * 21 + 1))))
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
			while (tab[j][i] == '\n')
				i++;
		}
		new_tab[j++] = ft_strsub(str, 0, ft_strlen(str));
	}
	free(str);
	return (new_tab);
}