/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaghettis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:44:02 by mayoub            #+#    #+#             */
/*   Updated: 2022/09/13 19:42:13 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_spaghetting(t_id *philo, int time_to_eat)
{
	long	sleep;
	long	start;

	sleep = philo->parse->time_to_sleep;
	start = philo->parse->time_to_start;
	if (actual_time() - philo->last_eat > philo->parse->time_to_die)
		philo->die = 1;
	pthread_mutex_lock(&philo->parse->print);
	printf("%ld	%d is eating\n", actual_time() - start, philo->id);
	pthread_mutex_unlock(&philo->parse->print);
	ft_usleep(time_to_eat);
	pthread_mutex_unlock(&philo->philoze->philo[philo->l_fork].fork);
	pthread_mutex_unlock(&philo->philoze->philo[philo->r_fork].fork);
	if (philo->nb_of_eat == philo->philoze->data.nb_must_eat)
		philo->philoze->yum += 1;
	philo->last_eat = actual_time();
	philo_rompiche(philo, philo->parse->time_to_sleep);
}
