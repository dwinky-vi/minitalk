/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:38:37 by vitaly            #+#    #+#             */
/*   Updated: 2021/09/07 16:05:05 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "head_minitalk.h"

int	main(void)
{
	struct sigaction	sa_signal;

	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_sigaction = ft_signal_handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	print_pid();
	while (21)
		pause();
	return (0);
}
