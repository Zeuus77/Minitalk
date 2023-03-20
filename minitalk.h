/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youel-id <youel-id@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:51:01 by youel-id          #+#    #+#             */
/*   Updated: 2023/02/21 09:51:04 by youel-id         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <string.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	handler(int sig, siginfo_t *info, void *text);
void	signal_sender(int pid, char *msg);
void	ft_bzero(void *s, size_t n);
int		ft_strlen(char *str);
void	signal_sender_bonus(int pid, char *msg, int len);
int		ft_putchar(int c);
int		ft_putnbr(int n);

#endif