/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:41:47 by mayoub            #+#    #+#             */
/*   Updated: 2022/07/22 18:57:23 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	dinner(t_id *philo)
{
	int	i;

	i = 0;
	philo->philoze->finish++;
	while (philo->philoze->finish != philo->philoze->data.nb_philo)
	{
		if (philo[i].nb_of_eat != philo->philoze->data.nb_must_eat)
			i++;
		if (i > philo->nb_of_eat)
			i = 0;
	}
	pthread_mutex_lock(&philo->parse->print);
	i = 0;
	// while (i != philo->philoze->data.nb_philo)
	// {
	// 	printf("nb of eat = %d, finish = %d, id = %d\n",philo[i].nb_of_eat, philo->philoze->finish, philo[i].id);
	// 	i++;
	// }
	printf("EVERYONE HAS FINISH\n");
	pthread_mutex_unlock(&philo->philoze->exit);
	//sleep(1);
}

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
		if (philo->nb_of_eat != philo->philoze->data.nb_must_eat)
			philo->nb_of_eat++;
		else if (philo->philoze->data.nb_must_eat >= 0)
			dinner(philo);
		//printf("nb of eat = %d, finish = %d, id = %d\n",philo->nb_of_eat, philo->philoze->finish, philo->id);
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
		pthread_detach(&philo->philo->ph[i]);
	}
	return (0);
}
