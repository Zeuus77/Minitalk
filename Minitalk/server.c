/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youel-id <youel-id@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 06:27:06 by youel-id          #+#    #+#             */
/*   Updated: 2023/01/24 06:27:08 by youel-id         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*b;

	b = (char *)s;
	i = 0;
	while (i < n)
	{
		b[i] = '\0';
		i++;
	}
}
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	ft_putnbr_fd(int n, int fd)
{
	long int	i;

	i = (long int)n;
	if (i < 0)
	{
		i *= -1;
		ft_putchar_fd('-', fd);
	}
	if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
	if (i >= 0 && i <= 9)
	{
		ft_putchar_fd(i + 48, fd);
	}
}


int power(int i , int j)
{
	int res;
	int k;

	k = 0;
	res = 1;
	while( k < j)
	{
		res = res * i;
		k++;
	}
	return(res);
}
//char convert(char *i)
//{
//int a = 0;
//int b = 0;
//	while (b <8)
//	{
//		a = a*2 + i[b];
//		b++;

//	}
//	return (a);
//}
char convert2(int *i)
{
	char c;
	int k = 7;
	int resulta = 0;
	while(k >= 0)
	{

		resulta = resulta + (i[k] * power(2,k));
		k--;
	}
	c = resulta;
	return c;
}
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

void ft_func(int *p)
{
	int i; 
	i = 0;
	while(i < 8)
	{
		p[i] =  0;
		i++;
	}

}


//}
void handler(int sig, siginfo_t *info, void *text)
{
	static int i = 0;
	char r;
	static int p[9];
	static int old_pid;
	
	(void)text;
	if (!old_pid)
		old_pid = info->si_pid;
	if (info->si_pid != old_pid)
	{
		// reset
		 i = 0;
		 ft_bzero(p, sizeof(int) * 9);
		 old_pid = info->si_pid;
	}
	if(sig == SIGUSR1)
		{	
			p[i++] = 1;
		}
	if (sig == SIGUSR2){
			p[i++] = 0;
	}
		if( i == 8)
		{
			p[8] = '\0';
			//printf("%d%d%d%d%d%d%d%d\n",p[0],p[1],p[2],p[3],p[4],p[5],p[6],p[7]);
			i = 0;
			r = convert2(p);
			write(1,&r,1);
			ft_bzero(p,sizeof(int) * 9);
		}
}

int main()
{
	struct sigaction action;
	ft_bzero(&handler,0);
	action.sa_sigaction = &handler;
	action.sa_flags = SA_SIGINFO;
	int pid  = getpid();
	printf("%d\n",pid );
	sigaction(SIGUSR1,&action,0);
	sigaction(SIGUSR2,&action,0);
	while(1){}
		return 0;

}