/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strct_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:19:51 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/09 17:46:48 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.c"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	//Il faudra aussi mettre count_points/sharp pour faire les cas d'erreurs
}					t_list;

t_list		*ft_check_tetri(char *str)
{
	/* But : Lorsque hash = 4 on va check chaque maillon de la liste qui sera
	 * egal a un tetrimino pour savoir si ce tetrimino existe et le quel c'est
	 * des 13 tetriminos existant
	*/
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list) * 20)))
		return (NULL);
	if (str == "#...#..##")
	{
		list->content = ".#...#..##";
		list->content_size = 11;
		list = list->next;
	}
	if (str == )
	list->content = 
	}
	return (list);
}
