/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:51:02 by jpelleti          #+#    #+#             */
/*   Updated: 2018/12/17 16:20:11 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_one_line(char *str)
{
	int i;

	i = 1;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (ft_strsub(str, 1, i - 1));
}

char	*ft_read(int fd, char **s)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	(!*s ? *s = ft_strnew(0) : 0);
	ret = 1;
	while (ft_strchr(*s, '\n') == NULL && ret > 0)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (NULL);
		buf[ret] = '\0';
		tmp = *s;
		*s = ft_strjoin(*s, buf);
		free(tmp);
		if (ft_strchr(*s, '\n') != NULL)
			break ;
	}
	return (*s);
}

t_gnl	*ft_lstnew_gnl(int fd, t_gnl *lst)
{
	t_gnl	*new;

	if (!(new = malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->s = ft_strnew(1);
	new->s[0] = '0';
	new->next = lst;
	return (new);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*lst;
	t_gnl			*tmp;
	char			*del;

	if (fd == -1)
		return (-1);
	tmp = lst;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
	{
		if (!(lst = ft_lstnew_gnl(fd, lst)))
			return (-1);
		tmp = lst;
	}
	if (!(ft_read(fd, &tmp->s)))
		return (-1);
	*line = ft_one_line(tmp->s);
	del = tmp->s;
	tmp->s = ft_strsub(tmp->s, ft_strlen(*line) + 1,
			ft_strlen(tmp->s) - ft_strlen(*line));
	free(del);
	if (!tmp->s[0])
		return (0);
	return (1);
}
