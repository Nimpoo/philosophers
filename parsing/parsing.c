/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:53:47 by mayoub            #+#    #+#             */
/*   Updated: 2022/07/02 23:07:38 by mayoub           ###   ########.fr       */
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
	if (argc <= 4 || argc > 6)
		return (1);
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 250)
		return (1);
	return (ICEBERG);
}
