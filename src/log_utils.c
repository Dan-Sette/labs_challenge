/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:55:36 by dalves-s          #+#    #+#             */
/*   Updated: 2022/02/27 01:00:37 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs_header.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
}

void	get_log_info(t_memory *inf)
{
	int		fd;
	int		fd_test;
	int		ret;
	char	*buf;
	int		i;

	fd_test = open("teste", O_WRONLY | O_CREAT | O_APPEND, 0777);
	ret = 62;
	i = 0;
	buf = ft_calloc(sizeof(char), 63);
	inf->mat_log = (char **)ft_calloc(sizeof(t_memory), 30);
	fd = open("log.txt", O_RDWR, 0777);
	while (ret == 62)
	{
		ret  = read(fd, buf, 62);
		if (ret != 62)
		{
			inf->mat_log[i] = NULL;
			break;
		}
		inf->mat_log[i] = ft_strdup(buf);
		if (i == 8)
			ft_putstr_fd(inf->mat_log[i], fd_test);
		i++;
	}
	close(fd);
	close(fd_test);
	free(buf);
	free_double(inf->mat_log);
}
