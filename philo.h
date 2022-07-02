/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:53:17 by mayoub            #+#    #+#             */
/*   Updated: 2022/07/02 23:21:35 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <pthread.h>

# define ICEBERG 0

/*----------STRUCT----------*/

typedef struct s_tabula_rasa{
	int			philo;
	t_status	status;
}t_tabula_rasa;

typedef struct s_status{
	int	time_to_fork;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_think;
	int	time_to_die;
}t_status;

/*-----------MAIN----------*/

int		main(int argc, char **argv);

/*----------UTILS----------*/

int		ft_atoi(const char *str);
int		ft_isdigit(int c);

/*---------PARSING---------*/

int		parsing(int argc, char **argv);

/*----------ERROR----------*/

void	error(void);

#endif
