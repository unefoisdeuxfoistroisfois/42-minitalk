/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:09:08 by britela-          #+#    #+#             */
/*   Updated: 2025/09/25 13:13:42 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receptionBit(int sigusr, siginfo_t *info, void *content)
{
	(void)content;
	static	int	tabBit[8];
	static	int	i;

	if (sigusr == SIGUSR1)
		tabBit[i] = 1;
	else if (sigusr == SIGUSR2)
		tabBit[i] = 0;
	i++;
	kill(info->si_pid, SIGUSR1);
	if (i == 8)
	{
		int	j;
		char	c;
		
		c = 0;
		j = 0;
		while (j < 8)
		{
			c = c * 2 + tabBit[j];
			j++;
		}
            	write(1, &c, 1);
		i = 0;
	}
}

void	ft_discussion(void)
{
	struct	sigaction action;
	int	nombreInfini;

	nombreInfini = 1;
    sigemptyset(&action.sa_mask);
	action.sa_sigaction = ft_receptionBit;
	action.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	write(1, "\n", 1);
//	signal(SIGUSR1, ft_receptionBit);
//	signal(SIGUSR2, ft_receptionBit);

	while(nombreInfini)
	{
		pause();
	}
}

int	main()
{
	int	varpid; //La fonction pid renvoie un entier

	varpid = getpid(); 
	ft_printf("PID : (%d)", varpid);

	ft_discussion();
	return(0);
}
