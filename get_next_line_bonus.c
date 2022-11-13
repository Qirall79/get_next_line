/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:05:05 by wbelfatm          #+#    #+#             */
/*   Updated: 2022/10/22 19:18:41 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	includes_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_remainder(char **holder, int start)
{
	int		len;
	char	*remainder;

	len = ft_strlen(*holder);
	if (len == 0)
	{
		free(*holder);
		*holder = NULL;
		return (NULL);
	}
	remainder = ft_substr(*holder, start, len);
	free(*holder);
	*holder = NULL;
	return (remainder);
}

char	*handle_line(char **holder)
{
	int		line_size;
	char	*line;

	line_size = includes_nl(*holder) + 1;
	line = ft_substr(*holder, 0, line_size);
	*holder = get_remainder(holder, line_size);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*holder[10000];
	char			buff[BUFFER_SIZE + 1];
	int				ret;

	ret = read(fd, buff, BUFFER_SIZE);
	if (!holder[fd])
		holder[fd] = ft_strdup("");
	while (ret >= 0)
	{
		buff[ret] = 0;
		holder[fd] = ft_strjoin(holder[fd], buff);
		if (includes_nl(holder[fd]) != -1)
			return (handle_line(&holder[fd]));
		if (ret == 0)
		{
			if (!holder[fd][0])
				break ;
			return (ft_strjoin(get_remainder(&holder[fd], 0), "\n"));
		}
		ret = read(fd, buff, BUFFER_SIZE);
	}
	free(holder[fd]);
	holder[fd] = NULL;
	return (NULL);
}
