/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:57:03 by dalves-s          #+#    #+#             */
/*   Updated: 2022/02/27 21:15:27 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs_header.h"



void	get_log(char **info)
{

	char	*method;
	char	**host;
	char	**urn;
	int		fd;
	char	*line_aux;
	char	*time_log;

	time_log = time_date();
	fd = open("log/log.txt", O_RDWR | O_APPEND, 0777);
	method = info[0];
	host = ft_split(info[3], '\r');
	urn = ft_split(info[1], '\n');
	line_aux = creat_log_line(method, host, urn, time_log);
	ft_putstr_fd(line_aux, fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	free_double(host);
	free_double(urn);
	free(method);
	free(line_aux);
}

char	*creat_log_line(char *method, char **host, char **urn, char *time_log)
{
	int		len;
	char	*ret_line;

	ret_line = ft_strdup("");
	len = ft_strlen(method);
	while (len < 7)
	{
		method = ft_strjoin(method, " ");
		len++;
		if (len == 7)
			method = ft_strjoin(method, "|");
	}
	ret_line = ft_strjoin(ret_line, method);
	len = ft_strlen(urn[0]);
	while (len < 9)
	{
		urn[0] = ft_strjoin(urn[0], " ");
		len++;
		if (len == 9)
			urn[0] = ft_strjoin(urn[0], "|");
	}
	ret_line = ft_strjoin(ret_line, urn[0]);
	len = ft_strlen(host[0]);
	while (len <= 21)
	{
		if (len < 21)
		{
			host[0] = ft_strjoin(host[0], " ");
			len++;
		}
		if (len == 21)
		{
			host[0] = ft_strjoin(host[0], "|");
			len++;
		}
	}
	ret_line = ft_strjoin(ret_line, host[0]);
	time_log = ft_strjoin(time_log, "|");
	ret_line = ft_strjoin(ret_line, time_log);

	return (ret_line);
}

void	create_log_file(void)
{
	int		fd;
	char	**matrix = NULL;
	char	*line_0 = "METHOD |   URN   |        HOST         |        TIME        |\n";
	char	*line_1 = "-------------------------------------------------------------";
	
	fd = ft_strlen(line_0);
	matrix = (char **)ft_calloc(sizeof(char), fd + 1);
	matrix[0] = ft_substr(line_0, 0, ft_strlen(line_0));
	matrix[1] = ft_substr(line_1, 0, ft_strlen(line_1));
	
	fd = open("log/log.txt", O_WRONLY | O_CREAT | O_APPEND, 0777);
	ft_putstr_fd(matrix[0], fd);
	ft_putstr_fd(matrix[1], fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	free_double(matrix);
}

char	*time_date(void)
{
	struct tm	*data_hora_atual; 
	time_t		timer;
	char		*now1;
	char		*now2;
	int			aux;

	time(&timer);
	data_hora_atual = localtime(&timer);
	now1 = ft_strdup("");
	now2 = ft_strdup("");
	aux = data_hora_atual->tm_hour;
	time_date_aux(&now1, now2, aux, 1);
	aux = data_hora_atual->tm_min;
	time_date_aux(&now1, now2, aux, 1);
	aux = data_hora_atual->tm_sec;
	time_date_aux(&now1, now2, aux, 3);
	aux = data_hora_atual->tm_mday;
	time_date_aux(&now1, now2, aux, 2);
	aux = data_hora_atual->tm_mon+1;
	time_date_aux(&now1, now2, aux, 2);
	aux = data_hora_atual->tm_year+1900;
	time_date_aux(&now1, now2, aux, 3);
	free(now2);
	return(now1);
}

void	time_date_aux(char **now1, char *now2, int aux, int c)
{
	now2 = ft_itoa(aux);
	if (aux <= 9)
		*now1 = ft_strjoin(*now1, "0");
	*now1 = ft_strjoin(*now1, now2);
	if (c == 1)
		*now1 = ft_strjoin(*now1, ":");
	if (c == 2)
		*now1 = ft_strjoin(*now1, "/");
	if (c == 3)
		*now1 = ft_strjoin(*now1, " ");
}
