/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:33:26 by britela-          #+#    #+#             */
/*   Updated: 2025/09/26 14:52:25 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_ack = 0;

void	reception_ack(int sig)
{
	(void)sig;
	g_ack = 1;
}

void	ft_convertinbit(pid_t argsPid, char c)
{
	int	i;
	int	newbit[8];

	i = 0;
	while (i < 8)
	{
		newbit[i] = c % 2;
		c = c / 2;
		i++;
	}
	i = 7;
	while (i >= 0)
	{
		if (newbit[i] == 1)
			kill(argsPid, SIGUSR1);
		else if (newbit[i] == 0)
			kill(argsPid, SIGUSR2);
		while (g_ack != 1)
		{
			pause();
		}
		g_ack = 0;
		i--;
	}
}

int	main(int argc, char **argv)
{
	int		npid;
	int		i;
	char	*message;

	if (argc != 3)
	{
		ft_printf ("Format correct : %s (PID) (message)\n", argv[0]);
		return (-1);
	}
	npid = ft_atoi(argv[1]);
	message = argv[2];
	signal(SIGUSR1, reception_ack);
	i = 0;
	while (message[i] != '\0')
	{
		ft_convertinbit(npid, message[i]);
		i++;
	}
	ft_convertinbit(npid, '\0');
	return (0);
}
