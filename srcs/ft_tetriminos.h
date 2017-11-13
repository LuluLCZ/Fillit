/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriminos.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:05:52 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/13 12:25:36 by llacaze          ###   ########.fr       */
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


typedef struct		s_tetris
{
	void				*content;
	size_t				content_size;
	struct s_tetris		*next;
}					t_tetris;

static char		*ft_buf_to_str(int fd);
static char		**ft_str_to_tab(char *str);
static char		**ft_str_split_nl(char **tab);
static char		**ft_split_dots(char **tab);
static int		ft_end_sharp(char *tab);
static int		check_tetriminos(char *str);

#endif
