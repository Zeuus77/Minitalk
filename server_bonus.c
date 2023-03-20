/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youel-id <youel-id@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 03:42:30 by youel-id          #+#    #+#             */
/*   Updated: 2023/03/04 03:42:31 by youel-id         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	convert2(int *str)
{
	int	index;
	int	count;
	int	output;

	index = -1;
	count = 0;
	output = 0;
	while (index++ <= 7)
	{
		if (str[count] == 1)
			output |= 1 << index;
		count++;
	}
	return (output);
}

void	handler(int sig, siginfo_t *info, void *text)
{
	static int	i;
	char		r;
	static int	p[8];
	static int	clt_pid;

	(void)text;
	if (clt_pid == 0)
		clt_pid = info->si_pid;
	if (info->si_pid != clt_pid)
	{
		i = 0;
		clt_pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		p[i++] = 1;
	if (sig == SIGUSR2)
		p[i++] = 0;
	if (i == 8)
	{
		i = 0;
		r = convert2(p);
		write(1, &r, 1);
		kill(info->si_pid, SIGUSR2);
		ft_bzero(p, sizeof(int) * 8);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	ft_bzero(&action, sizeof(action));
	action.sa_sigaction = &handler;
	action.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (1)
		pause();
	return (0);
}
