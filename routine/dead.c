/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:34:49 by mayoub            #+#    #+#             */
/*   Updated: 2022/08/02 16:08:27 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*tombstone(void *arg)
{
	t_id	*philo;
	long	start;
	long	die;
	long	last_eat;

	philo = (t_id *) arg;
	start = philo->parse->time_to_start;
	die = philo->parse->time_to_die;
	last_eat = philo->last_eat;
	while (1)
	{
		last_eat = philo->parse->time_to_die + start;
		if (die <= philo->parse->time_to_eat || ((actual_time() - start) - last_eat) >= die)
		{
			ft_usleep(die);
			pthread_mutex_lock(&philo->parse->print);
			printf("%ld	%d is dead\n", actual_time() - start, philo->id);
			pthread_mutex_unlock(&philo->philoze->exit);
			return (0);
		}
		if ((die <= philo->parse->time_to_sleep || ((actual_time() - start) - last_eat) >= die) && philo->philoze->dead > 0)
		{
			ft_usleep(die);
			pthread_mutex_lock(&philo->parse->print);
			printf("%ld	%d is dead\n", actual_time() - start, philo->id);
			pthread_mutex_unlock(&philo->philoze->exit);
			return (0);
		}
		while (philo->think == 1)
		{
			if (philo->parse->nb_philo == 1)
			{
				ft_usleep(die);
				pthread_mutex_lock(&philo->parse->print);
				printf("%ld	%d is dead\n", actual_time() - start, philo->id);
				pthread_mutex_unlock(&philo->philoze->exit);
				return (0);
			}
			last_eat = philo->parse->time_to_die + start;
			if (((actual_time() - start) - last_eat) >= die)
			{
				ft_usleep(die);
				pthread_mutex_lock(&philo->parse->print);
				printf("%ld	%d is dead\n", actual_time() - start, philo->id);
				pthread_mutex_unlock(&philo->philoze->exit);
				return (0);
			}
		}
	}
}
