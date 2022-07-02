/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:55:44 by mayoub            #+#    #+#             */
/*   Updated: 2022/07/02 16:16:07 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define ICEBERG 0

void	*test2(void *arg)
{
	int	i;

	i = 0;
	// while (i <= 100)
	// {
		printf("\033[0;37m%s\033[0m\n", (char *) arg);
	// 	i++;
	// }
	// sleep(3);
	// printf("TASK FINISHED\n");
	return (arg);
}

void	*test(void *arg)
{
	int	i;

	i = 0;
	// while (i <= 100)
	// {
		printf("\033[0;32m%s\033[0m\n", (char *) arg);
	// 	i++;
	// }
	// sleep(3);
	// printf("TASK FINISHED\n");
	return (arg);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;
	int			i;
	char		*s1;
	char		*s2;

	i = 0;
	pthread_create(&t1, NULL, &test, "SALUUT");
	pthread_create(&t2, NULL, &test2, "COUCOU");
	pthread_join(t1, (void **) &s1);
	pthread_join(t2, (void **) &s2);
	printf("%s, %s\n", s1, s2);
	return (ICEBERG);
}
