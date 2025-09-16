/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:33:26 by britela-          #+#    #+#             */
/*   Updated: 2025/09/16 14:43:12 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_conversionEnBit(char c)
{
	int	i;
	int	newBit[8];

	i = 0;
	while (i != 7)
	{
		newBit[i] = c % 2;
		c = c / 2;
		i++;
	}
	i = 7;
	while (i >= 0)
	{
		ft_printf("%d", newBit[i]);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int 	nPid;
	char	*message;
	int	i;

	if (argc == 3)
	{
		ft_printf("communique : ");
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
		ft_conversionEnBit(message[i]);
		i++;
	}
	return (0);
}
