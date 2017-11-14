/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriminos.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:05:52 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/14 18:54:54 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TETRIMINOS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# define FT_TETRIMINOS_H

# define S1 "#...#..##"
# define S2 "#...#...##"
# define S3 "##...#...#"
# define S4 "##..#...#"
# define S5 "#.###"
# define S6 "###...#"
# define S7 "##...##"
# define S8 "##.##"
# define S9 "#..##..#"
# define S10 "#...##...#"
# define S11 "##..##"
# define S12 "#...#...#...#"
# define S13 "####"
# define S14 "###.#"
# define S15 "#...###"
# define S16 "#..##...#"
# define S17 "#...##..#"
# define S18 "#..###"
# define S19 "###..#"

typedef struct		s_list
{
	char				*content;
	size_t				content_size;
	struct s_list		*next;
}					t_list;

typedef struct		ListeRepere
{
	t_list				*first;
	t_list				*last;
	int					len;
}					Liste;

typedef struct		s_coordonnees
{
	int		*ordonnees;
	int		*abcisse;
}					t_coord;


static char		*ft_buf_to_str(int fd);
static char		**ft_str_to_tab(char *str);
static char		**ft_str_split_nl(char **tab);
static char		**ft_split_dots(char **tab);
static int		ft_end_sharp(char *tab);
static int		check_tetriminos(char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
static int		ft_tab_check_tetri(char **tab);
static void		ft_erreurs(char **tab);

#endif
