/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:36:16 by tmalheir          #+#    #+#             */
/*   Updated: 2023/11/29 14:43:57 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	idx;
	char	*dst;
	size_t	len;

	if (!s)
		return (NULL);
	idx = 0;
	len = ft_strlen(s);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (idx < len)
	{
		dst[idx] = s[idx];
		idx++;
	}
	dst[idx] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s3;
	size_t			idx;
	size_t			len_s1;
	size_t			len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = (char *)malloc(len_s1 + len_s2 + 1);
	if (!s3)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		s3[idx] = s1[idx];
		idx++;
	}
	while (s2[idx - len_s1])
	{
		s3[idx] = s2[idx - len_s1];
		idx++;
	}
	s3[idx] = '\0';
	return (s3);
}

size_t	ft_strlen(const char *s)
{
	int	idx;

	idx = 0;
	while (s && s[idx])
		idx++;
	return (idx);
}
