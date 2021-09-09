/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_s_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:03:21 by vitaly            #+#    #+#             */
/*   Updated: 2021/09/09 23:55:41 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_minitalk.h"

void	get_bit(int bit, int client_pid)
{
	static char	one_char = 0;
	static int	digit = 0;

	one_char += (bit << digit);
	digit++;
	if (digit > 7)
	{
		if (one_char == '\0')
		{
			write(1, "\n", 1);
			if (kill(client_pid, SIGUSR2) == -1)
				report_an_error("Error\nbad SIGUSR2 in get_bit\n");
		}
		else
		{
			write(1, &one_char, 1);
			if (kill(client_pid, SIGUSR1) == -1)
				report_an_error("Error\nbad SIGUSR1 in get_bit\n");
		}
		one_char = 0;
		digit = 0;
	}
}

void	ft_signal_handler(int sig, siginfo_t *act, void *oldact)
{
	int	client_pid;

	(void)oldact;
	client_pid = act->si_pid;
	if (sig == SIGUSR1)
		get_bit(1, client_pid);
	else if (sig == SIGUSR2)
		get_bit(0, client_pid);
}

void	print_pid(void)
{
	ft_putstr_fd("\e[1;32mPID -> ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\e[0m\n", 1);
}
