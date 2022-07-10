/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rompiche.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:57:52 by mayoub            #+#    #+#             */
/*   Updated: 2022/07/10 20:33:11 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_rompiche(t_id *philo, int time_to_sleep)
{
	long	old;

	old = actual_time();
	pthread_mutex_lock(&philo->parse->print);
	printf("%ld	%d is sleeping\n", (actual_time() - old), philo->id);
	pthread_mutex_unlock(&philo->parse->print);
	ft_usleep(time_to_sleep);
	printf("%ld	%d is think\n", (actual_time() - old), philo->id);
}
