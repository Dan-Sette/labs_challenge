/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:28:54 by dalves-s          #+#    #+#             */
/*   Updated: 2022/02/25 17:29:19 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs_header.h"

char	*concat_char(char *str,
						  size_t size,
						  unsigned int num,
						  unsigned int is_negative)
{
	str[size] = '\0';
	while (size--)
	{
		str[size] = (num % 10) + 48;
		num /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}

int	ft_numlen(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		len++;
	n /= 10;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t			n_len;
	unsigned int	is_negative;
	char			*str;

	n_len = ft_numlen(n);
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	str = malloc(sizeof(char) * (n_len + 1));
	if (str == NULL)
		return (NULL);
	return (concat_char(str, n_len, (unsigned int)n, is_negative));
}
