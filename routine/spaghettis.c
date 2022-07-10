/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaghettis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:44:02 by mayoub            #+#    #+#             */
/*   Updated: 2022/07/10 20:36:24 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_spaghetting(t_id *philo, int time_to_eat)
{
	long	old;

	old = actual_time();
	pthread_mutex_lock(&philo->parse->print);
	printf("%ld	%d is eating\n", (actual_time() - old), philo->id);
	pthread_mutex_unlock(&philo->parse->print);
	ft_usleep(time_to_eat);
	pthread_mutex_unlock(&philo->philoze->philo[philo->l_fork].fork);
	pthread_mutex_unlock(&philo->philoze->philo[philo->r_fork].fork);
	philo_rompiche(philo, philo->parse->time_to_sleep);
}
