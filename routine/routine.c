/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:41:47 by mayoub            #+#    #+#             */
/*   Updated: 2022/07/10 22:31:01 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_id	*philo;
	long	old;

	philo = (t_id *) arg;
	old = actual_time();
	if (philo->id % 2 == 0)
		ft_usleep(100);
	while (1)
	{
		pthread_mutex_lock(&philo->philoze->philo[philo->l_fork].fork);
		pthread_mutex_lock(&philo->parse->print);
		printf("%ld	%d has taken a fork\n", actual_time() - philo->parse->time_to_start, philo->id);
		pthread_mutex_unlock(&philo->parse->print);
		pthread_mutex_lock(&philo->philoze->philo[philo->r_fork].fork);
		pthread_mutex_lock(&philo->parse->print);
		printf("%ld	%d has taken a fork\n", actual_time() - philo->parse->time_to_start, philo->id);
		pthread_mutex_unlock(&philo->parse->print);
		philo_spaghetting(philo, philo->parse->time_to_eat);
	}
	return (arg);
}

int	philo_generator(t_tabula_rasa *philo)
{
	int	i;

	i = -1;
	philo->data.time_to_start = actual_time();
	while (++i < philo->data.nb_philo)
	{
		philo->philo[i].parse = &philo->data;
		pthread_create(&philo->philo->ph, NULL, &routine, &philo->philo[i]);
	}
	return (0);
}
