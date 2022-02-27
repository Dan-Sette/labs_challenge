/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:49:40 by dalves-s          #+#    #+#             */
/*   Updated: 2022/02/24 15:49:41 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs_header.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size_s;
	size_t	max_len;

	size_s = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (size_s < start)
	{
		sub = (char *)ft_calloc(sizeof(char), 1);
		if (!sub)
			return (NULL);
		return (sub);
	}
	max_len = size_s - start;
	if (len > max_len)
		len = max_len;
	sub = (char *)ft_calloc(sizeof(char), len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}
