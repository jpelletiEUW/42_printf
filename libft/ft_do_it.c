/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:16:49 by jpelleti          #+#    #+#             */
/*   Updated: 2018/11/16 09:58:10 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_do_it(const char *s, char c, char **res)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			res[k][j] = s[i];
			j++;
			i++;
		}
		res[k][j] = '\0';
		if (s[i] || s[i - 1] != c)
			k++;
		if (s[i + 1] == '\0')
			i++;
	}
	res[k] = NULL;
	return (res);
}
