/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rompiche.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:57:52 by mayoub            #+#    #+#             */
/*   Updated: 2022/07/23 16:45:01 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_rompiche_forever(t_id *philo)
{
	philo->philoze->yum += 1;
	pthread_mutex_lock(&philo->parse->print);
	printf("%ld	%d is sleeping\n",
		actual_time() - philo->parse->time_to_start, philo->id);
	pthread_mutex_unlock(&philo->parse->print);
	while (1)
		ft_usleep(500);
}

void	philo_thinking_forever(t_id *philo)
{
	philo->philoze->yum += 1;
	pthread_mutex_lock(&philo->parse->print);
	printf("%ld	%d is thinking\n",
		actual_time() - philo->parse->time_to_start, philo->id);
	pthread_mutex_unlock(&philo->parse->print);
	while (1)
		ft_usleep(500);
}

void	philo_rompiche(t_id *philo, int time_to_sleep)
{
	long	start;

	start = philo->parse->time_to_start;
	pthread_mutex_lock(&philo->parse->print);
	printf("%ld	%d is sleeping\n", actual_time() - start, philo->id);
	pthread_mutex_unlock(&philo->parse->print);
	ft_usleep(time_to_sleep);
	printf("%ld	%d is think\n", actual_time() - start, philo->id);
}
