/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:33:26 by britela-          #+#    #+#             */
/*   Updated: 2025/09/15 17:30:53 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int nPid;

	if (argc == 3)
	{
		ft_printf("communique : ")
	}
	/* repeter la commande kill(shell) fais un ligne de commande 
	 * kill -USR1 numeropid
	 * kill -USR2 3328
	 * en fonction c'est autre
	 * kill(pid, -USR1) -usr1 signal a envoyé*/

	//conversion en int
	nPid = ft_atoi(argv[1]);

	kill(nPid, 
	return (0);
}
