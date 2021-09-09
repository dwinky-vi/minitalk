/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:42:10 by vitaly            #+#    #+#             */
/*   Updated: 2021/09/09 14:43:39 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_minitalk.h"

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
