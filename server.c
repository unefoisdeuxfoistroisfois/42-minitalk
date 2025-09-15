/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:09:08 by britela-          #+#    #+#             */
/*   Updated: 2025/09/15 17:02:00 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receptionBit(int sigusr)
{
	if (sigusr == SIGUSR1)
	{
		ft_printf("bradley");
	}
	else if (sigusr == SIGUSR2)
	{
		ft_printf("ouss");
	}
}

void	ft_discussion(void)
{
	int nombreInfini;

	nombreInfini = 1;
	signal(SIGUSR1, ft_receptionBit);
	signal(SIGUSR2, ft_receptionBit);

	while(nombreInfini)
	{
		pause();
	}
}

int	main()
{
	int	varpid; //La fonction pid renvoie un entier

	varpid = getpid(); 
	ft_printf("PID : %d", varpid);

	ft_discussion();
	return(0);
}
