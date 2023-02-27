/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youel-id <youel-id@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 06:26:58 by youel-id          #+#    #+#             */
/*   Updated: 2023/01/24 06:27:01 by youel-id         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<signal.h>
#include"minitalk.h"
#include <strings.h>


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



void signal_sender(int pid, char *msg)
{
	int i;
 
 
	int bit;
	i = 0;
	bit = 0;
	while(msg[i])
	{
		while ( bit < 8 )
		{
			if((msg[i] & (1 << bit)) != 0)
				kill(pid, SIGUSR1); 
			else
				kill(pid, SIGUSR2); 
			bit++;
			usleep(100);
		}
 
		bit = 0;
		i++;
	}
	
}

int main(int ac , char **av)
{ 
	if(ac == 3)
	{

		int pid  = ft_atoi(av[1]);
		if(pid <= 0)
			write(1,"erreur",6);
		else
		signal_sender(pid, av[2]);
		

		return 0;
	}
}