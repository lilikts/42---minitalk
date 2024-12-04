/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:40:14 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/04 17:22:43 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(void)
{
	ft_printf("Server PID: %d\n", getpid());

	while (1)
	{
		signal(SIGUSR2, );
		signal(SIGUSR1,);
		pause();
	}
}


