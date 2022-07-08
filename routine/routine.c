/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:41:47 by mayoub            #+#    #+#             */
/*   Updated: 2022/07/08 19:49:37 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_id	*philo;
	long	old;

	philo = (t_id *) arg;
	old = actual_time();
	if (philo->id % 2)
		ft_usleep(philo->parse->time_to_eat / 2);
	pthread_mutex_lock(&philo[philo->l_fork].fork);
	//pthread_mutex_lock(&philo->parse->print);
	printf("%ld	%d has taken a fork\n", (actual_time() - old), philo->id);
	//pthread_mutex_unlock(&philo->parse->print);
	pthread_mutex_lock(&philo[philo->r_fork].fork);
	//pthread_mutex_lock(&philo->parse->print);
	printf("%ld	%d has taken a fork\n", (actual_time() - old), philo->id);
	//pthread_mutex_unlock(&philo->parse->print);
	return (arg);
}

int	philo_generator(t_tabula_rasa *philo)
{
	int	i;

	i = 0;
	while (i < philo->data.nb_philo)
	{
		philo->philo[i].parse = &philo->data;
		pthread_create(&philo->philo->ph, NULL, &routine, &philo->philo[i]);
		i++;
	}
	return (0);
}
