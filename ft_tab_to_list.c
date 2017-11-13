/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:01:06 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/13 19:46:22 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CheckMap/ft_tetriminos.h"
#include "CheckMap/Libft/ft_lstnew.c"
#include "CheckMap/ft_buf_to_tab.c"
#include "CheckMap/Libft/ft_lstadd.c"

t_list		*ft_tab_to_list(char **tab)
{
	int		j;
	t_list	*end;
	t_list	*tetriminos;

	while (tab[j])
		j++;
	j--;
	end->next = ft_lstnew(tab[j], ft_strlen(tab[j]));
	while (j >= 0)
	{
		tetriminos->content = tab[j];
		tetriminos->content_size = ft_strlen(tab[j]);
		ft_lstadd(&end, tetriminos);
		end = end->next;
		j--;
	}
//	while (tmp->next != NULL)
//		tmp = tmp->next;
	tetriminos->next = NULL;
	return (tetriminos);
}
int		main(int ac, char **av)
{
	//int		i;
	int		fd;
	t_list	*tetri;
	t_list	*cpytab;
	//char	*str;
	(void)ac;

	fd = open(av[1], O_RDONLY);
	tetri = ft_tab_to_list(ft_str_to_tab(ft_buf_to_str(fd)));
	
	cpytab = NULL;
	while (tetri)
	{
		write(1, "b", 1);
		printf("%s\n", tetri->content);
		tetri = tetri->next;
	}
	return (0);
}
