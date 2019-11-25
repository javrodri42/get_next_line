/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 10:14:38 by javrodri          #+#    #+#             */
/*   Updated: 2019/11/25 14:33:37 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char		*ft_strnew(void)
{
	char *ret;

	if (!(ret = (char *)malloc(sizeof(char))))
		return (0);
	ret[0] = '\0';
	return (ret);
}

static ssize_t	pos_nl(char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int		free_cache(char **cache, int ret)
{
	if (*cache)
	{
		free(*cache);
		*cache = 0;
	}
	return (ret);
}

static int		extract(char **line, char **cache, int idx)
{
	char	*tmp;
	int		ret;

	if (idx >= 0)
	{
		if (!(*line = ft_substr(*cache, 0, idx)))
			return (free_cache(cache, -1));
		if (!(tmp = ft_substr(*cache, idx + 1, ft_strlen(*cache) - idx - 1)))
			return (free_cache(cache, -1));
		ret = 1;
	}
	else
	{
		if (!(*line = ft_substr(*cache, 0, ft_strlen(*cache))))
			return (free_cache(cache, -1));
		tmp = 0;
		ret = 0;
	}
	free_cache(cache, 0);
	*cache = tmp;
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	ssize_t		r_size;
	char		buff[BUFFER_SIZE + 1];
	static char	*cache[4096];
	char		*tmp;

	if (BUFFER_SIZE == 0)
		return (-1);
	if (fd < 0 || !line)
		return (free_cache(&cache[fd], -1));
	while ((r_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r_size] = '\0';
		if (!(tmp = ft_strjoin(cache[fd], buff, r_size)))
			return (free_cache(&cache[fd], -1));
		free_cache(&cache[fd], 0);
		cache[fd] = tmp;
		if (pos_nl(cache[fd]) != -1)
			break ;
	}
	if (r_size < 0)
		return (free_cache(&cache[fd], -1));
	if (r_size == 0 && (!cache[fd] || *cache[fd] == '\0')
		&& (*line = ft_strnew()))
		return (free_cache(&cache[fd], 0));
	return (extract(line, &cache[fd], pos_nl(cache[fd])));
}
