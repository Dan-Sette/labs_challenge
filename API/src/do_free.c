/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:29:25 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/02/25 16:44:29 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs_header.h"

void	free_double(char **str)
{
	int	x;

	x = 0;
	if (str != NULL)
	{
		while (str[x] != NULL)
		{
			free(str[x]);
			str[x] = NULL;
			x++;
		}
		free(str);
		str = NULL;
	}
}
