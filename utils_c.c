/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:57:27 by vitaly            #+#    #+#             */
/*   Updated: 2021/09/07 16:56:54 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_minitalk.h"

void	prepare_argument(int argc, char **argv, int *pid, char **message)
{
	if (argc < 3)
	{
		ft_putstr_fd("Error\ninvalid argument", 1);
		exit(1);
	}
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
					exit(1);
			}
			else
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			i *= 2;
			usleep(100);
		}
		if (message[k] == '\0')
			return (0);
		k++;
	}
}

void	error(int sig)
{
	(void)sig;
	ft_putstr_fd("u", 1);
	exit(0);
}