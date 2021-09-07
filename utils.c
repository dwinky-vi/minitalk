/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:38:47 by vitaly            #+#    #+#             */
/*   Updated: 2021/09/07 13:45:43 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	ft_isdigit(int ch)
{
	return ('0' <= ch && ch <= '9');
}

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t	k;

	k = 0;
	if (num == 0)
		return (0);
	while (k != num - 1 && s1[k] == s2[k] && s1[k] != '\0')
		k++;
	return ((unsigned char)s1[k] - (unsigned char)s2[k]);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	k;

	k = 0;
	sign = 1;
	result = 0;
	while ((9 <= str[k] && str[k] <= 13) || str[k] == 32)
		k++;
	if (ft_strncmp("-2147483648", str, 11) == 0)
		return (-2147483648);
	if (str[k] == '-')
	{
		sign = -1;
		k++;
	}
	else if (str[k] == '+')
		k++;
	while (ft_isdigit(str[k]))
	{
		result *= 10;
		result += str[k] - '0';
		k++;
	}
	return (sign * result);
}
