/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:38:47 by vitaly            #+#    #+#             */
/*   Updated: 2021/09/09 14:47:21 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (0 <= n && n <= 9)
	{
		num = n + (int)('0');
		write(fd, &num, 1);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	ft_putnbr_fd(n % 10, fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		while (*s != '\0')
			write(fd, s++, 1);
}

void	report_an_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}
