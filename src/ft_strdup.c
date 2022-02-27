/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:41:43 by dalves-s          #+#    #+#             */
/*   Updated: 2022/02/25 17:42:13 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs_header.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	dst = (char *) malloc((sizeof(char) * len) + 1);
	if (dst == NULL)
		return (NULL);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
