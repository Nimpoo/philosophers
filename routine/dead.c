/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:34:49 by mayoub            #+#    #+#             */
/*   Updated: 2022/09/09 21:00:38 by mayoub           ###   ########.fr       */
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
			printf("last eat = %ld, time to eat = %d, die = %i\n", actual_time() - philo->last_eat, philo->parse->time_to_eat, philo->parse->time_to_die);
			printf("actual time = %ld, last eat = %ld\n", actual_time(), philo->last_eat);
			printf("%ld	%d is dead.......... EAT\n", actual_time() - start, philo->id);
			usleep(die * 1000);
			pthread_mutex_unlock(&philo->philoze->exit);
			return (0);
		}
	}
}
