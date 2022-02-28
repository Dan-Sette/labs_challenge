/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:02:37 by dalves-s          #+#    #+#             */
/*   Updated: 2022/02/27 19:47:55 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs_header.h"

static size_t	WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	size_t realsize = size * nmemb;
	struct MemoryStruct *mem = (struct MemoryStruct *)userp;
	
	char *ptr = realloc(mem->memory, mem->size + realsize + 1);
	if(!ptr) {
		/* out of memory! */
		printf("not enough memory (realloc returned NULL)\n");
		return 0;
	}
	
	mem->memory = ptr;
	memcpy(&(mem->memory[mem->size]), contents, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;
	
	return realsize;
}

char	*handle_curl(void)
{
	CURL *curl_handle;
	CURLcode res;
	
	struct MemoryStruct chunk;
	
	chunk.memory = malloc(1);  /* will be grown as needed by the realloc above */
	chunk.size = 0;    /* no data at this point */
	
	curl_global_init(CURL_GLOBAL_ALL);
	
	/* init the curl session */
	curl_handle = curl_easy_init();
	
	/* specify URL to get */
	curl_easy_setopt(curl_handle, CURLOPT_URL, "https://rickandmortyapi.com/api/location/6");
	
	/* send all data to this function  */
	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
	
	/* we pass our 'chunk' struct to the callback function */
	curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
	
	/* some servers do not like requests that are made without a user-agent
		field, so we provide one */
	curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
	
	/* get it! */
	res = curl_easy_perform(curl_handle);
	
	/* check for errors */
	if(res != CURLE_OK)
	{
		fprintf(stderr, "curl_easy_perform() failed: %s\n",
		curl_easy_strerror(res));
		return ("curl_easy_perform() failed");
	}
	//   else {
	//     /*
	//      * Now, our chunk.memory points to a memory block that is chunk.size
	//      * bytes big and contains the remote file.
	//      *
	//      * Do something nice with it!
	//      */
	
	//     printf("%lu bytes retrieved\n", (unsigned long)chunk.size);
	//   }
	
	/* cleanup curl stuff */
	curl_easy_cleanup(curl_handle);
	
	/* we are done with libcurl, so clean it up */
	curl_global_cleanup();
	return(chunk.memory);
	}