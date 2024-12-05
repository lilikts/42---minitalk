/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:40:14 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/05 13:57:08 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(void)
{
	ft_printf("Server PID: %d\n", getpid());

	while (1)
	{
		signal(SIGUSR2, receive);
		signal(SIGUSR1, receive);
		pause();
	}
	return (0);
}

static void receive(int signal)
{
	char *message = NULL;
	char *error_check = NULL;
	char c;
	int binary;
	int i;
	
	binary = 0;
	i = 0;
	binary <<= 1;
	if (signal == SIGUSR1)
		binary |= 1;
	i++;
	if (i == 8)
	{
		c = binary;
		message = make_message_string(c, &message);
		binary = 0;
		i = 0;
	}
}

char *make_message_string(char c, char **message)
{
	char *error_check;
		
	if (c == '\0')
	{
		if (*message)
		{
			ft_printf("%s", *message);
			free(*message);
		}
		return (NULL);
	}
	else
	{
		if (!message)
			error_check = ft_strdup((const char *)&c);
		else
			error_check = ft_strjoin(*message, (const char *)&c);
	}
	free(*message);
	message = error_check;
	return (*message);
}
