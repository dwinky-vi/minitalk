/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:38:37 by vitaly            #+#    #+#             */
/*   Updated: 2021/09/09 23:50:03 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_minitalk.h"

int	main(void)
{
	struct sigaction	sa_signal;

	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_sigaction = ft_signal_handler;
	if (sigaction(SIGUSR1, &sa_signal, NULL) == -1)
		report_an_error("Error\nbad SIGUSR1\n");
	if (sigaction(SIGUSR2, &sa_signal, NULL) == -1)
		report_an_error("Error\nbad SIGUSR2\n");
	print_pid();
	while (21)
		pause();
	return (0);
}
