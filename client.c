/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:38:55 by vitaly            #+#    #+#             */
/*   Updated: 2021/09/09 14:50:01 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_minitalk.h"

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	prepare_argument(argc, argv, &pid, &message);
	signal(SIGUSR2, ft_close_client);
	send_message(pid, message);
	while (21)
		pause();
	return (0);
}
