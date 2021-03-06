/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:57:27 by vitaly            #+#    #+#             */
/*   Updated: 2021/09/10 00:08:25 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_minitalk.h"

void	prepare_argument(int argc, char **argv, int *pid, char **message)
{
	if (argc < 3)
		report_an_error("Error\ninvalid argument");
	*pid = ft_atoi(argv[1]);
	*message = argv[2];
}

int	send_message(int pid, char *message)
{
	int		k;
	int		i;

	k = 0;
	while (21)
	{
		i = 1;
		while (i <= 128)
		{
			if ((i & message[k]) > 0)
			{
				if (kill(pid, SIGUSR1) == -1)
					report_an_error("Error\nbad SIGUSR1 in send_message\n");
			}
			else
				if (kill(pid, SIGUSR2) == -1)
					report_an_error("Error\nbad SIGUSR2 in send_message\n");
			i *= 2;
			usleep(65);
		}
		if (message[k] == '\0')
			return (0);
		k++;
	}
}

void	ft_close_client(int sig)
{
	(void)sig;
	exit(0);
}
