/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:09:08 by britela-          #+#    #+#             */
/*   Updated: 2025/09/14 20:03:40 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main()
{
	int	varpid; //La fonction pid renvoie un entier

	varpid = getpid(); 
	printf("%d", varpid);
	return(0);
}
