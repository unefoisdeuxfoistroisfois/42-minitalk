/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:33:26 by britela-          #+#    #+#             */
/*   Updated: 2025/09/25 13:18:29 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t get_ack = 0;

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
	/* repeter la commande kill(shell) fais un ligne de commande 
	 * kill -USR1 numeropid
	 * kill -USR2 3328
	 * en fonction c'est autre
	 * kill(pid, -USR1) -usr1 signal a envoyé*/

	//int kill(pid_t pid, int sig);
	//conversion en int
	nPid = ft_atoi(argv[1]);
	message = argv[2];

    struct sigaction action;

	sigemptyset(&action.sa_mask);
    action.sa_handler = reception_ack;
    action.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &action, NULL);

	i = 0;
	while (message[i] != '\0')
	{
		ft_conversionEnBit(nPid, message[i]);
		i++;
	}
	ft_conversionEnBit(nPid, '\0');   // insère un saut de ligne immédiat
	return (0);
}
