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
#define MINITALK_H

#include<unistd.h>
#include<stdio.h>
#include<signal.h>

int	ft_atoi(const char *str);
void handler(int sig);
void signal_sender(int pid, char *message);

#endif