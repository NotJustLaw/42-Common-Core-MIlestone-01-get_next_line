/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justlaw <justlaw@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:11:35 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/12 22:37:06 by justlaw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_next(char *s);
static char	*ft_line(char *s);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;
	int			r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	r = 1;
	while (r > 0 && (!stash || !ft_strchr(stash, '\n')))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (free(buf), free(stash), stash = NULL, NULL);
		buf[r] = 0;
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	if (!stash)
		return (NULL);
	line = ft_line(stash);
	stash = ft_next(stash);
	return (line);
}

static char	*ft_line(char *s)
{
	char	*line;
	int		i;

	if (!s || !*s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

static char	*ft_next(char *s)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (!s || !s[i])
		return (free(s), NULL);
	if (!s[i + 1])
		return (free(s), NULL);
	res = malloc(ft_strlen(&s[i + 1]) + 1);
	if (!res)
		return (free(s), NULL);
	i++;
	j = 0;
	while (s[i])
		res[j++] = s[i++];
	res[j] = 0;
	free(s);
	return (res);
}
