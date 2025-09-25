/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:09:08 by britela-          #+#    #+#             */
/*   Updated: 2025/09/25 16:16:41 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receptbit(int sigusr, siginfo_t *info, void *content)
{
	static int	tabbit[8];
	static int	i;
	int			j;
	char		c;

	(void)content;
	if (sigusr == SIGUSR1)
		tabBit[i] = 1;
	else if (sigusr == SIGUSR2)
		tabBit[i] = 0;
	i++;
	if (i == 8)
	{
		c = 0;
		j = 0;
		while (j < 8)
		{
			c = c * 2 + tabBit[j];
			j++;
		}
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		i = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

void	ft_discussion(void)
{
	struct sigaction	action;
	int					ninfini;

	ninfini = 1;
	sigemptyset(&action.sa_mask);
	action.sa_sigaction = ft_receptionBit;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	write (1, "\n", 1);
	while (ninfini)
	{
		pause();
	}
}

int	main(void)
{
	int	varpid;

	varpid = getpid();
	ft_printf ("PID : (%d)", varpid);
	ft_discussion();
	return (0);
}
