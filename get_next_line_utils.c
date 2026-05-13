/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusakaki <yusakaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 00:03:01 by yusakaki          #+#    #+#             */
/*   Updated: 2026/05/14 00:44:16 by yusakaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	if (!s)
// 		return (0);
// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	if (!s)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (unsigned char)c)
// 			return ((char *)s + i);
// 		i++;
// 	}
// 	if ((unsigned char)c == '\0')
// 		return ((char *)s + i);
// 	return (NULL);
// }

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*d;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	d = (char *)malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

// char	*ft_strdup(const char *s)
// {
// 	char	*dup;
// 	size_t	len;
// 	size_t	i;

// 	if (!s)
// 		return (NULL);
// 	len = ft_strlen(s);
// 	dup = (char *)malloc(len + 1);
// 	if (!dup)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		dup[i] = s[i];
// 		i++;
// 	}
// 	dup[len] = '\0';
// 	return (dup);
// }

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	return (res);
}

// char	*ft_strjoin(const char *s1, const char *s2)
// {
// 	char	*res;
// 	size_t	len1;
// 	size_t	len2;
// 	size_t	i;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
// 	i = 0;
// 	while (s1[i])
// 	{
// 		res[i] = s1[i];
// 		i++;
// 	}
// 	while (*s2)
// 	{
// 		res[i] = *s2;
// 		s2++;
// 		i++;
// 	}
// 	res[i] = '\0';
// 	return (res);
// }

// char	*ft_strjoin(const char *s1, const char *s2)
// {
// 	char	*result;
// 	size_t	len1;
// 	size_t	len2;
// 	size_t	i;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	result = (char *)malloc(len1 + len2 + 1);
// 	if (!result)
// 		return (NULL);
// 	i = 0;
// 	while (i < len1)
// 	{
// 		result[i] = s1[i];
// 		i++;
// 	}
// 	i = 0;
// 	while (i < len2)
// 	{
// 		result[len1 + i] = s2[i];
// 		i++;
// 	}
// 	result[len1 + len2] = '\0';
// 	return (result);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
