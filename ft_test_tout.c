/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_tout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:33:25 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/09 20:15:51 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.c"
#include "ft_tetriminos.h"
#include "ft_tetriminos.c"
#include "ft_split.c"

static char		*ft_split(char *str);

static char		*ft_test_tetri(char *str);

char	*ft_strdup(const char *src);

size_t	ft_strlen(const char *str);
/*
static	int		ft_count_place(int fd)
{
	int		count_char;
	int		count_point;
	int		count_hash;
	char	buf;

	count_hash = 0;
	count_point = 0;
	count_char = 0;
	while (read(fd, &buf, 1) == 1)
	{
		if (buf == '.')
			count_point++;
		if (buf == '#')
			count_hash++;
		count_char++;
	}
	return (count_char);
}
*/
static char		*ft_buf_to_str(int fd)
{
	char	buf;
	int		i;
	char	*str;
//	int		count_char;
	int		reead;

	reead = read(fd, &buf, 1);
	i = 0;
//	count_char = ft_count_place(fd2);
	if (!(str = (char *)malloc(sizeof(char) * 50)))
		return (NULL);
	while (buf != '\0' && reead == 1)
	{
		str[i] = buf;
		i++;
		reead = read(fd, &buf, 1);
	}
	str[i] = '\0';
	return (str);
}

static char		*ft_split_nl(char *str)
{
	char	*new_str;
	int		i;
	//int		count_char;
	int		j;

	j = 0;
	i = 0;
//	count_char = ft_count_place(fd);
	if (!(new_str = (char *)malloc(sizeof(char) * 5000)))
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
	{
		new_str[j] = str[i];
		j++;
		i++;
		while (str[i] == '\n')
			i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

/*static char		*ft_split_four(char *str)
{
	char	*new_str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * 50)))
		return (NULL);
	while (str[i] == '.' && str[i] != '#')
		i++;
	printf("%d", i);
	if (i >= 4)
	{
		k = 5;
		while (str[k])
		{
			new_str[j] = str[k];
			j++;
			k++;
		}
		new_str[j] = '\0';
	}
	else
		return (str);
	return (new_str);
}*/

static char		*ft_split_first_points(char *str)
{
	char	*new_str;
	int		i;
	int		j;
	int		hash;

	hash = 0;
	i = 0;
	j = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * 50)))
		return (NULL);
	while (str[i] == '.' && str[i] != '#')
		i++;
	while (i < 25 && hash < 4)
	{
		//while (str[i] == '.' && i < 4)
		//	i++;
		if (str[i] == '#')
			hash++;
		new_str[j] = str[i];
		if (hash == 4)
			break;
		i++;
		j++;
	}
	new_str[j + 1] = '\0';
	return(new_str);
}

int		main(int ac, char **av)
{
	char	*str;
	int		fd;
	//(void)ft_count_place;

	if (!(str = (char *)malloc(sizeof(char) * 50000)))
		return (0);
	fd = open(av[1], O_RDWR);
	if (ac != 2)
		return (0);
//	printf("%d\n", ft_count_place(fd));
//	printf("%s", ft_buf_to_str(fd));
//	printf("%s", ft_split_nl(ft_buf_to_str(fd)));
//	printf("%s", ft_split_first_points(ft_split_nl(ft_buf_to_str(fd))));
//	printf("%s", ft_test_tetri(ft_split_first_points(ft_split_nl(ft_buf_to_str(fd)))));
//	printf("%s", ft_split_first_points(ft_split_four(ft_split_nl(ft_buf_to_str(fd)))));
	str = ft_buf_to_str(fd);
	str = ft_split_nl(str);
	str = ft_split_first_points(str);
	str = ft_test_tetri(str);
	printf("%s", ft_split(str));
//	printf("%s", ft_split(ft_test_tetri(ft_split_first_points(ft_split_nl(ft_buf_to_str(fd))))));
	close(fd);
	return (0);
}
