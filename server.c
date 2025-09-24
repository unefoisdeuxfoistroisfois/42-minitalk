/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:09:08 by britela-          #+#    #+#             */
/*   Updated: 2025/09/24 16:58:26 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receptionBit(int sigusr, siginfo_t *info, void *content)
{
		void(context);
	static	int	tabBit[8];
	static	int	i;

	if (sigusr == SIGUSR1)
		tabBit[i] = 1;
	else if (sigusr == SIGUSR2)
		tabBit[i] = 0;
	i++;
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
	kill(info->si_pid, SIGUSR1);
	}
}

void	ft_discussion(void)
{
	int	nombreInfini;
	siginfo_t	info= ft_receptionBit();

	nombreInfini = 1;
	sigaction(SIGUSR1, info, NULL);
//	signal(SIGUSR1, ft_receptionBit);
	write(1, "\n", 1);
	sigaction(SIGUSR2, info, NULL);
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
