/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:39:38 by cacharle          #+#    #+#             */
/*   Updated: 2020/05/09 11:19:12 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		st_find_newline(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

static int		st_free_return(char **ptr, char **ptr2, int ret)
{
	if (ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
	if (ptr2 != NULL)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	return (ret);
}

static int		st_read_line(int fd, char **line, char *rest)
{
	int		ret;
	int		split_at;
	char	*buf;

	if ((buf = malloc(sizeof(char) * (FT_GETLINE_BUFFER_SIZE + 1))) == NULL)
		return (st_free_return(line, NULL, FT_ERROR));
	while ((ret = read(fd, buf, FT_GETLINE_BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((split_at = st_find_newline(buf)) != -1)
		{
			ft_strcpy(rest, buf + split_at + 1);
			buf[split_at] = '\0';
			if ((*line = ft_strjoinf(*line, buf, FT_STRJOINF_FST)) == NULL)
				return (st_free_return(&buf, NULL, FT_ERROR));
			return (st_free_return(&buf, NULL, FT_LINE));
		}
		if ((*line = ft_strjoinf(*line, buf, FT_STRJOINF_FST)) == NULL)
			return (st_free_return(&buf, NULL, FT_ERROR));
	}
	if (ret == -1)
		return (st_free_return(&buf, line, FT_ERROR));
	return (st_free_return(&buf, NULL, ret));
}

/*
** if has rest:
**     if rest has newline:
**         push rest until newline in line, shift rest
**         return LINE_READ
**     else:
**         push rest in line
**
** while can read fd in buf
**     if buf has newline:
**         push buf until newline in line
**         push buf after newline in rest
**         return LINE_READ
**     push buf in line
**
** return FTNL_EOF
*/

int				ft_getline(int fd, char **line)
{
	int			split_at;
	static char	rest[OPEN_MAX][FT_GETLINE_BUFFER_SIZE + 1] = {{0}};

	if (fd < 0 || fd > OPEN_MAX || line == NULL || FT_GETLINE_BUFFER_SIZE <= 0)
		return (FT_ERROR);
	if ((*line = ft_strdup("")) == NULL)
		return (FT_ERROR);
	if (rest[fd][0] == '\0')
		return (st_read_line(fd, line, rest[fd]));
	if ((split_at = st_find_newline(rest[fd])) != -1)
	{
		free(*line);
		if ((*line = (char*)malloc(sizeof(char) * (split_at + 1))) == NULL)
			return (FT_ERROR);
		ft_strncpy(*line, rest[fd], split_at);
		(*line)[split_at] = '\0';
		ft_strcpy(rest[fd], rest[fd] + split_at + 1);
		return (FT_LINE);
	}
	free(*line);
	if (!(*line = (char*)malloc(sizeof(char) * (ft_strlen(rest[fd]) + 1))))
		return (FT_ERROR);
	ft_strcpy(*line, rest[fd]);
	rest[fd][0] = '\0';
	return (st_read_line(fd, line, rest[fd]));
}