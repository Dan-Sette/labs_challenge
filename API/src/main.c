/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:46:53 by dalves-s          #+#    #+#             */
/*   Updated: 2022/02/27 21:15:03 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs_header.h"

void	up_server(struct mg_connection *c, int ev, void *ev_data, void *fn_data)
{
	char					**info;
	char					**verb;
	char					*json;
	struct mg_http_message	*keep_msg;
	verb = ft_split("POST GET DELETE", ' ');
	
	if (ev == MG_EV_HTTP_MSG)
	{
		keep_msg = (struct mg_http_message *) ev_data;
		info = ft_split(keep_msg->method.ptr, ' ');		

		if (mg_http_match_uri(keep_msg, "/"))
		{
			if (info[0][0] == verb[0][0])
				mg_http_reply(c, 200, "", "{\"triedPOST\": true}", 123);
			else
				mg_http_reply(c, 200, "", "{\"path\":\"/home\"}", 123);
			get_log(info);
		}
		else if (mg_http_match_uri(keep_msg, "/rm"))
		{
			json = handle_curl();
			mg_http_reply(c, 200, "", json, 123);
			free(json);
			get_log(info);
		}
		else if (mg_http_match_uri(keep_msg, "/user"))
		{
			mg_http_reply(c, 200, "", "{\"path\":\"/user\"}", 123);
			get_log(info);
		}
	}
	(void)fn_data;
}

int		main(void)
{
	struct	mg_mgr mgr;
	int		fd;

	fd = open("log/log.txt", O_WRONLY);
	if (fd < 0)
		create_log_file();
	else
		close(fd);
	mg_mgr_init(&mgr);
	if (!mg_http_listen(&mgr, "http://localhost:8000", up_server, NULL))
		return (1);
	while (1)
		mg_mgr_poll(&mgr, 1000);
	mg_mgr_free(&mgr);
	close(fd);

	return (0);
}
