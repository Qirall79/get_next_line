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

char	*ft_free(char *holder)
{
	free(holder);
	holder = NULL;
	return (NULL);
}

char	*read_content(int fd, char *holder)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, &buff, BUFFER_SIZE);
		if (ret == -1)
			return (ft_free(holder));
		buff[ret] = 0;
		tmp = ft_strjoin(holder, buff);
		ft_free(holder);
		holder = tmp;
		if (ft_strchr(holder, '\n'))
			break ;
	}
	if (ret == 0 && !holder[0])
		return (ft_free(holder));
	return (holder);
}

char	*extract_line(char *holder, int *pos)
{
	char	*line;
	int		i;

	i = 0;
	if (!holder[0])
		return (NULL);
	while (holder[i] && holder[i] != '\n')
		i++;
	line = ft_substr(holder, 0, i);
	*pos = i + 1;
	return (line);
}

char	*get_remainder(char *holder, int pos)
{
	char	*remainder;

	if (!holder[pos])
	{
		ft_free(holder);
		return (NULL);
	}
	remainder = ft_substr(holder, pos, ft_strlen(holder) - 1);
	ft_free(holder);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*holder[10000];
	char		*line;
	int			pos;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!holder[fd])
		holder[fd] = ft_strdup("");
	holder[fd] = read_content(fd, holder[fd]);
	if (!holder[fd])
		return (NULL);
	line = extract_line(holder[fd], &pos);
	holder[fd] = get_remainder(holder[fd], pos);
	return (line);
}
