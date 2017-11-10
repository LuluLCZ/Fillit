/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_listes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:19:35 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/10 11:15:54 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tetriminos.h"
#include "../../Projets/Libft/ft_lstnew.c"
#include "../../Projets/Libft/libft.h"
#include "../../Projets/Libft/ft_memcpy.c"
static char		*ft_buf_to_lst(int fd)
{
	int		i;
	int		j;
	char	buf;
	char	*str;
	int		input;
	char	*new_str;
	
	if (!(new_str = ))
	if (!(str = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	i = 0;
	j = 0;
	input = read(fd, &buf, 1);
	if (input == 1)
	{
		new_str = ft_lstnew(&buf, input);
		while (input == 1 && buf != '\0')
		{
			str[i] = buf;
			i++;
			input = read(fd, &buf, 1);
		}
	}
	str[i] = '\0';
	return ();
}

int		main(int ac, char **av)
{
	int		fd;
	
	if (ac != 2)
		return (0);
	fd = open (av[1], O_RDONLY);
	printf("%s", ft_buf_to_lst(fd));
	return (0);
}
