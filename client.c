/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:33:26 by britela-          #+#    #+#             */
/*   Updated: 2025/09/22 16:44:41 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		{
			kill(argsPid, SIGUSR1);
		}
		else if (newBit[i] == 0)
		{
			kill(argsPid, SIGUSR2);
		}
		usleep(100);
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
	/* repeter la commande kill(shell) fais un ligne de commande 
	 * kill -USR1 numeropid
	 * kill -USR2 3328
	 * en fonction c'est autre
	 * kill(pid, -USR1) -usr1 signal a envoyé*/

	//int kill(pid_t pid, int sig);
	//conversion en int
	nPid = ft_atoi(argv[1]);
	message = argv[2];

	i = 0;
	while (message[i] != '\0')
	{
		ft_conversionEnBit(nPid, message[i]);
		i++;
	}
	ft_conversionEnBit(nPid, '\n');   // insère un saut de ligne immédiat
	return (0);
}
