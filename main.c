/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:35:30 by mayoub            #+#    #+#             */
/*   Updated: 2022/07/05 21:24:07 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// // int	philo_generator(int argc, t_tabula_rasa *philo)
// // {
// // 	int	i;

// // 	i = argc;
// // 	while (i < 0)
// // 	{
// // 		pthread_create(philo->ph, NULL, )
// // 		i++;
// // 	}
// // }

int	init_philo(t_tabula_rasa *philo)
{
	int	i;

	i = 0;
	if (!(philo->philo = (t_id *)malloc(sizeof(*(philo->philo)) * philo->data.nb_philo)))
		return (1);
	while (i < philo->data.nb_philo)
	{
		philo->philo[i].id = i;
		philo->philo[i].nb_of_eat = 0;
		philo->philo[i].last_eat = i;
		philo->philo[i].l_fork = i;
		philo->philo[i].r_fork = (i + 1) % philo->data.nb_philo;
		philo->philo[i].position = i;
		pthread_mutex_init(&philo->philo[i].fork, NULL);
		i++;
	}
	return (0);
}

int	init_data(int argc, char **argv, t_tabula_rasa *philo)
{
	int	i;

	i = 1;
	(void) argc;
	if (argv[5] <= 0)
		return (1);
	philo->data.nb_philo = ft_atoi(argv[1]);
	philo->data.time_to_die = ft_atoi(argv[2]);
	philo->data.time_to_eat = ft_atoi(argv[3]);
	philo->data.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->data.nb_of_eat = ft_atoi(argv[5]);
	else
		philo->data.nb_of_eat = -1;
	if (init_philo(philo) == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_tabula_rasa	philo;
	int				i;

	i = 0;
	if (parsing(argc, argv) == 1)
		error();
	if (init_data(argc, argv, &philo) == 1)
		error();
	return (ICEBERG);
}
