/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:41:47 by mayoub            #+#    #+#             */
/*   Updated: 2022/07/23 16:45:13 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	dinner(t_id *philo)
{
	int	i;

	i = 0;
	if (i < philo->philoze->data.nb_philo)
	{
		if (philo->philoze->yum != philo->philoze->data.nb_philo)
		{
			return (0);
		}
		i++;
	}
	pthread_mutex_lock(&philo->parse->print);
	printf("EVERYONE HAS FINISH\n");
	pthread_mutex_unlock(&philo->philoze->exit);
	return (1);
}

void	*chef(void *arg)
{
	t_id	*philo;

	philo = (t_id *) arg;
	while (1)
	{
		if (dinner(philo) && philo->philoze->data.nb_must_eat >= 0)
			return (0);
	}
}

void	*routine(void *arg)
{
	t_id	*philo;
	long	start;

	philo = (t_id *) arg;
	start = philo->parse->time_to_start;
	if (philo->id % 2 == 0)
		ft_usleep(100);
	while (1)
	{
		if (philo->nb_of_eat <= philo->philoze->data.nb_must_eat)
			philo->nb_of_eat++;
		else if (philo->nb_of_eat == philo->philoze->data.nb_must_eat)
			philo_thinking_forever(philo);
		pthread_mutex_lock(&philo->philoze->philo[philo->l_fork].fork);
		pthread_mutex_lock(&philo->parse->print);
		printf("%ld	%d has taken a fork\n", actual_time() - start, philo->id);
		pthread_mutex_unlock(&philo->parse->print);
		pthread_mutex_lock(&philo->philoze->philo[philo->r_fork].fork);
		pthread_mutex_lock(&philo->parse->print);
		printf("%ld	%d has taken a fork\n", actual_time() - start, philo->id);
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
		pthread_detach(&philo->philo->ph[i]);
		pthread_create(&philo->finish, NULL, &chef, &philo->philo[i]);
		pthread_detach(&philo->finish[i]);
		// pthread_create(&philo->tombstone, NULL, &routine, &philo->philo[i]);
		// pthread_detach(&philo->tombstone[i]);
	}
	return (0);
}
