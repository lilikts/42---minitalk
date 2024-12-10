/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:40:14 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/10 16:04:29 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive(int signal)
{
	static int		bits;
	static int		i;
	unsigned char	c;

	bits <<= 1;
	if (signal == SIGUSR2)
		bits = bits | 1;
	i++;
	if (i == 8)
	{
		c = bits;
		write (1, &c, 1);
		bits = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	signal(SIGUSR1, receive);
	signal(SIGUSR2, receive);
	while (1)
	{
		pause();
	}
	return (0);
}
