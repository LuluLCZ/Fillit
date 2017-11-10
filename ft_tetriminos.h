/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriminos.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:05:52 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/10 14:14:17 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TETRIMINOS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# define FT_TETRIMINOS_H
# define S1 "#...#..##"
# define S5 "#.###"
# define S8 "##.##"
# define S9 "#..##..#"

typedef struct		s_tetris
{
	void				*content;
	size_t				content_size;
	struct s_tetris		*next;
}					t_tetris;

#endif
