/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:33:26 by britela-          #+#    #+#             */
/*   Updated: 2025/09/25 14:14:24 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int  get_ack = 0;

void	reception_ack(int sig)
{
	(void)sig;
	get_ack = 1;
}

void	ft_conversionEnBit(pid_t argsPid, char c)
{
	int	i;
	int	newBit[8];

	i = 0;
	while (i < 8)
	{
		newBit[i] = c % 2;
		c = c / 2;
		i++;
	}
	i = 7;
	while (i >= 0)
	{
		if (newBit[i] == 1)
			kill(argsPid, SIGUSR1);
		else if (newBit[i] == 0)
			kill(argsPid, SIGUSR2);
		while(get_ack != 1)
		{
			pause();
		}
		get_ack = 0;
		i--;
	}
}

int	main(int argc, char **argv)
{
	int 	nPid;
	char	*message;
	int	i;

	if (argc != 3)
	{
		ft_printf("ciao : ");
		return (-1);
	}
	nPid = ft_atoi(argv[1]);
	message = argv[2];

	signal(SIGUSR1, reception_ack);
	
	i = 0;
	while (message[i] != '\0')
	{
		ft_conversionEnBit(nPid, message[i]);
		i++;
	}
	ft_conversionEnBit(nPid, '\0');   // insère un saut de ligne immédiat
	return (0);
}
