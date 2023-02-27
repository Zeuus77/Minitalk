/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youel-id <youel-id@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 02:38:48 by youel-id          #+#    #+#             */
/*   Updated: 2022/10/24 21:26:12 by youel-id         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

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
	/*int main()
	{
		char str[] = " -+15156";
		printf("%d",ft_atoi(str));
		return(0);	
	}*/