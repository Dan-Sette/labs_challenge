/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:50:00 by dalves-s          #+#    #+#             */
/*   Updated: 2022/02/24 15:50:01 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs_header.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if ((src == 0) || (dst == 0))
		return (0);
	if (size > 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
