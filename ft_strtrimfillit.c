/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lulu <Lulu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 22:06:58 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/10 16:43:48 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char		*detect_after(char *s2, char const *s, size_t a, size_t i, char c)
{
	size_t		j;

	j = 0;
	while (s[i - 1] != c)
		i--;
	if (!(s2 = (char *)malloc(sizeof(char) * ((i - a) + 1))))
		return (NULL);
	while (a < i)
		s2[j++] = s[a++];
	s2[j] = '\0';
	return (s2);
}

char			*ft_strtrim(char const *s, char c)
{
	char		*s2;
	size_t		i;
	size_t		a;
	size_t		j;

	j = 0;
	a = 0;
	i = 0;
	if (s)
	{
		if (!(s2 = (char *)malloc(sizeof(char) * ((i - a) + 1))))
			return (NULL);
		while (s[i] != c && s[i])
			i++;
		if (s[i] == '\0')
		{
			s2[a] = s[i];
			return (s2);
		}
		a = i;
		i = ft_strlen(s);
		s2 = detect_after(s2, s, a, i, c);
		return (s2);
	}
	return (NULL);
}
