/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:35:30 by mayoub            #+#    #+#             */
/*   Updated: 2022/09/13 11:30:52 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_tabula_rasa *philo)
{
	int	i;

	i = -1;
	philo->philo = malloc(sizeof(t_id) * philo->data.nb_philo);
	if (!(philo->philo))
		return (1);
	while (++i < philo->data.nb_philo)
	{
		philo->philo[i].id = i + 1;
		philo->philo[i].nb_of_eat = 0;
		philo->philo[i].last_eat = actual_time();
		philo->philo[i].l_fork = i;
		philo->philo[i].r_fork = (i + 1) % philo->data.nb_philo;
		pthread_mutex_init(&philo->philo[i].fork, NULL);
		philo->philo[i].philoze = philo;
	}
	pthread_mutex_init(&philo->data.print, NULL);
	pthread_mutex_init(&philo->exit, NULL);
	return (0);
}

int	init_data(int argc, char **argv, t_tabula_rasa *philo)
{
	(void) argc;
	if (argv[5])
		if (ft_atoi(argv[5]) <= 0)
			return (1);
	philo->data.nb_philo = ft_atoi(argv[1]);
	philo->data.time_to_die = ft_atoi(argv[2]);
	philo->data.time_to_eat = ft_atoi(argv[3]);
	philo->data.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		philo->data.nb_must_eat = ft_atoi(argv[5]);
		philo->yum = 0;
	}
	else
	{
		philo->data.nb_must_eat = -1;
		philo->yum = -1;
	}
	if (init_philo(philo) == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_tabula_rasa	philo;

	if (parsing(argc, argv) == 1)
		error();
	if (init_data(argc, argv, &philo) == 1)
		error();
	if (philo_generator(&philo) == 1)
		error();
	pthread_mutex_lock(&philo.exit);
	pthread_mutex_lock(&philo.exit);
	pthread_mutex_unlock(&philo.exit);
	return (ICEBERG);
}
