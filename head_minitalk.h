/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_minitalk.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:38:00 by vitaly            #+#    #+#             */
/*   Updated: 2021/09/07 18:23:12 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_MINITALK_H
# define HEAD_MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <signal.h>

void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int ch);
int		ft_strncmp(const char *s1, const char *s2, size_t num);
int		ft_atoi(const char *str);
void	get_bit(int bit, int client_pid);
void	ft_signal_handler(int sig, siginfo_t *act, void *oldact);
void	print_pid(void);
void	prepare_argument(int argc, char **argv, int *pid, char **message);
int		send_message(int pid, char *message);
void	error(int sig);

#endif

/* HEAD_MINITALK_H */
