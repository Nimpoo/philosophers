/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:53:17 by mayoub            #+#    #+#             */
/*   Updated: 2022/09/13 13:56:18 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>

# define ICEBERG	0

/*----------STRUCT----------*/

typedef struct s_data{
	long int		time_to_start;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				nb_must_eat;
	int				nb_philo;
	pthread_mutex_t	print;
}t_data;

struct	s_id;

typedef struct s_tabula_rasa{
	int				yum;
	t_data			data;
	struct s_id		*philo;
	pthread_t		finish;
	pthread_t		tombstone;
	pthread_mutex_t	exit;
	struct timeval	tm;
}t_tabula_rasa;

typedef struct s_id{
	pthread_t		ph;
	int				id;
	long int		last_eat;
	int				nb_of_eat;
	int				l_fork;
	int				r_fork;
	int				die;
	pthread_mutex_t	fork;
	t_data			*parse;
	t_tabula_rasa	*philoze;
}t_id;

/*-----------MAIN----------*/

int			main(int argc, char **argv);

/*----------INITS----------*/

int			init_data(int argc, char **argv, t_tabula_rasa *philo);
int			philo_generator(t_tabula_rasa *philo);

/*----------ACTION----------*/

void		*routine(void *arg);
void		*tombstone(void *arg);
void		philo_spaghetting(t_id *philo, int time_to_eat);
void		philo_rompiche(t_id *philo, int time_to_sleep);
int			philo_tombstone(t_id *philo, int time_to_die);
int			is_dead(t_id *philo);

/*----------UTILS----------*/

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		ft_usleep(long int ms);
long int	actual_time(void);

/*---------PARSING---------*/

int			parsing(int argc, char **argv);

/*----------ERROR----------*/

void		error(void);

#endif
