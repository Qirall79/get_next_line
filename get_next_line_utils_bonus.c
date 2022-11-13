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
#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*result;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = -1;
	result = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (++i < s1_len)
		result[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		result[i + s1_len] = s2[i];
	result[s1_len + s2_len] = '\0';
	return (result);
}

char	*ft_substr(char *str, int start, int end)
{
	int		i;
	char	*result;

	i = start;
	result = malloc((end - start + 1) * sizeof(char));
	while (i < end)
	{
		result[i - start] = str[i];
		i++;
	}
	result[end - start] = 0;
	return (result);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i])
		i++;
	dup = (char *) malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup[i] = 0;
	while (i--)
		dup[i] = src[i];
	return (dup);
}
