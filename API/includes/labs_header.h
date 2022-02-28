/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labs_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:48:43 by dalves-s          #+#    #+#             */
/*   Updated: 2022/02/27 19:07:17 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABS_HEADER_H
# define LABS_HEADER_H
# include "mongoose.h"
# include <stdio.h>
# include <curl/curl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <time.h>
# include <curl/curl.h>

struct MemoryStruct {
	char *memory;
	size_t size;
};

int			main(void);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_strdup(const char *src);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
char		*ft_itoa(int n);
void		get_log(char	**info);
void		free_double(char **str);
void		create_log_file(void);
char		*time_date(void);
void		time_date_aux(char **now1, char *now2, int aux, int c);
char		*creat_log_line(char *method, char **host, char **uri, char *time_log);
void		ft_putnbr_fd(int n, int fd);
char		*handle_curl(void);

#endif