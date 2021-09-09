/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:38:55 by vitaly            #+#    #+#             */
/*   Updated: 2021/09/10 00:00:49 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_minitalk.h"

void	ft_feedback(int sig)
{
	(void)sig;
	write(1, "response received\n", 18);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	prepare_argument(argc, argv, &pid, &message);
	signal(SIGUSR1, ft_feedback);
	signal(SIGUSR2, ft_close_client);
	send_message(pid, message);
	while (21)
		pause();
	return (0);
}
