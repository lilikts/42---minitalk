/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:39:57 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/04 17:19:58 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send(char *str, int pid)
{
	int shift;
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		shift = 7;
		while (shift >= 0)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift--;
			usleep(100);
		}
		i++;
	}
}

int main (int argc, char *argv[])
{
	if (argc == 3)
	{
		int pid;
		
		pid = ft_atoi(argv[1]);
		send(argv[2], pid);
		return (0);
	}
	else
		ft_printf("Usage: ./client <server_pid> 'Message'");
	return (0);
}
