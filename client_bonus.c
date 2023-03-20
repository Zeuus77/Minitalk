/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youel-id <youel-id@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 05:41:51 by youel-id          #+#    #+#             */
/*   Updated: 2023/03/04 05:41:52 by youel-id         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_incri = 0;

void	handler_bonus(int sig, siginfo_t *info, void *text)
{
	(void)info;
	(void)text;
	if (sig == SIGUSR2)
	{
		g_incri++;
	}
}

int	ft_atoi(const char *str)
{
	int				i;
	int				res;
	int				n;
	unsigned char	*tmpstr;

	tmpstr = ((unsigned char *)str);
	i = 0;
	n = 1;
	res = 0;
	while (tmpstr[i] == '\n' || tmpstr[i] == '\t' || tmpstr[i] == '\r'
		|| tmpstr[i] == '\v' || tmpstr[i] == '\f' || tmpstr[i] == ' ')
		i++;
	if (tmpstr[i] == '-' || tmpstr[i] == '+')
	{
		if (tmpstr[i] == '-')
			n = -1;
		i++;
	}
	while ((tmpstr[i] >= '0' && tmpstr[i] <= '9'))
	{
		res = res * 10 + (tmpstr[i] - 48);
		i++;
	}
	return ((res * n));
}

void	signal_sender_bonus(int pid, char *msg, int len)
{
	int	i;
	int	bit;

	i = 0;
	if (msg == '\0')
		kill(pid, SIGUSR2);
	while (msg[i])
	{
		bit = 0;
		while (bit < 8)
		{
			if ((msg[i] & (1 << bit)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(250);
		}
		i++;
	}
	if (i == len)
	{
		write(1, "MESSAGE RECIEVE", 15);
	}
}

int	main(int ac, char **av)
{
	int					len;
	int					pid;
	struct sigaction	action;

	action.sa_sigaction = &handler_bonus;
	action.sa_flags = 0;
	sigaction(SIGUSR2, &action, NULL);
	if (ac == 3)
	{
		len = ft_strlen(av[2]);
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			write(1, "erreur", 6);
		}
		else
		{
			signal_sender_bonus(pid, av[2], len);
		}
		return (0);
	}
}
