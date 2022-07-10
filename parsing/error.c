/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:38:15 by mayoub            #+#    #+#             */
/*   Updated: 2022/07/02 20:53:18 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	error(void)
{
	printf("Error\nPlease tape \"./philo [nb of philo]");
	printf(" [time to die] [time to eat] [time to sleep]");
	printf("\x1b[32m(OPTIONAL ---> [nb of each time philo must eat])\x1b[0m\".\n");
	printf("				      {in ms}	    {in ms}	   {in ms}\n");
	exit(0);
}
