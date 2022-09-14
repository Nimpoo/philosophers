/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:34:49 by mayoub            #+#    #+#             */
/*   Updated: 2022/09/13 17:06:13 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*tombstone(void *arg)
{
	t_id	*philo;
	long	start;
	long	die;

	philo = (t_id *) arg;
	start = philo->parse->time_to_start;
	die = philo->parse->time_to_die;
	while (1)
	{
		if ((actual_time() - philo->last_eat) > die)
		{
			pthread_mutex_lock(&philo->parse->print);
			printf("%ld	%d is dead\n", actual_time() - start, philo->id);
			pthread_mutex_unlock(&philo->philoze->exit);
			return (0);
		}
	}
}
