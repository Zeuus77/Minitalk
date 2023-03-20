/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youel-id <youel-id@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 03:13:59 by youel-id          #+#    #+#             */
/*   Updated: 2023/03/20 03:14:01 by youel-id         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long int	i;
	int			c;

	c = 0;
	i = (long int)n;
	if (i < 0)
	{
		i *= -1;
		c += ft_putchar('-');
	}
	if (i > 9)
	{
		c += ft_putnbr(i / 10);
		c += ft_putnbr(i % 10);
	}
	if (i >= 0 && i <= 9)
	{
		c += ft_putchar(i + 48);
	}
	return (c);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
