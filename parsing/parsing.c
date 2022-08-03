/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:53:47 by mayoub            #+#    #+#             */
/*   Updated: 2022/08/02 15:38:45 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || (c == 43 || c == 45))
		return (1);
	return (0);
}

int	parsing(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (argc < 5 || argc > 6)
		return (1);
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			if (ft_atoi(argv[i]) < 0)
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		return (1);
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return (1);
	return (ICEBERG);
}
