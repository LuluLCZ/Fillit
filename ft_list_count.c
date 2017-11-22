/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:58:34 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/16 18:39:44 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:01:06 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/14 14:56:52 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CheckMap/ft_tetriminos.h"
#include "CheckMap/Libft/ft_lstnew.c"
#include "CheckMap/ft_buf_to_tab.c"
#include "CheckMap/Libft/ft_lstadd.c"
#include "CheckMap/Libft/ft_strcpy.c"

void		initialisation(Liste *Liste)
{
	liste->first = NULL;
	liste->last = NULL;
	liste->len = 0;
}

int			ins_in_empty_list(Liste *liste, char **tab)
{
	int		j;
	t_list	*new_elem;

	//liste = initialisation(liste);
	write(1, "e", 1);
	j = 0;
	if (!(new_elem = (t_list *)malloc(sizeof(t_list) * 25)))
		return (-1);
	if (!(new_elem->content = (char *)malloc(sizeof(char *) * 25)))
		return (-1);
	ft_strcpy(new_elem->content, tab[j]);
	new_elem->next = NULL;
	liste->first = new_elem;
	liste->last = new_elem;
	liste->len++;
	return (0);
}

int			ins_start_list(Liste *liste, char **tab)
{
	int		j;
	int		i;
	t_list	*add;

	i = 0;
	if (!(add = (t_list *)malloc(sizeof(t_list) * (27 * 25 + 1))))
		return (-1);
	if (!(add->content = (char *)malloc(sizeof(char *) * ft_strlen(*tab) + 1)))
		return (-1);
	ft_strcpy(add->content, *tab);
	add->next = liste->first;
	liste->first = add;
	liste->len++;
	tab++;
	if (*tab)
		ins_start_list(liste, tab);
	return (0);
}

int		aff_liste(char **tab)
{
	Liste	*liste;
	t_list	*cur;

	if (!(liste = (Liste *)malloc(sizeof(Liste) * (27 * 25 + 1))))
		return (-1);
	initialisation(liste);
	ins_start_list(liste, tab);
	cur = liste->first;
	while (cur != NULL)
	{
		printf("%s\n", cur->content);
		cur = cur->next;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	char	**tab;
	//char	*str;
	(void)ac;

	fd = open(av[1], O_RDONLY);
	tab = ft_str_split_nl(ft_str_to_tab(ft_buf_to_str(fd)));
	tab = ft_split_dots(tab);
	aff_liste(tab);
	return (0);
}
