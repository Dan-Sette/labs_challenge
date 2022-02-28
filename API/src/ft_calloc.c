/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:50:05 by dalves-s          #+#    #+#             */
/*   Updated: 2022/02/24 15:50:06 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs_header.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	ret = malloc(nmemb * size);
	if (!(ret))
		return (NULL);
	ft_memset(ret, 0, nmemb * size);
	return (ret);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	c_1;

	str = s;
	i = 0;
	c_1 = (char)c;
	while (i < n)
	{
		str[i] = c_1;
		i++;
	}
	return ((void *)str);
}
