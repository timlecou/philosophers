/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:06:33 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/23 15:49:31 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

extern	t_data	g_data;

int		ft_parsing(int ac, char **av)
{
	g_data.ph_number = ft_atoi_philo(av[1]);
	g_data.time_to_die = ft_atoi_philo(av[2]);
	g_data.time_to_die = ft_atoi_philo(av[2]);
	g_data.number = g_data.ph_number;
	g_data.time_to_eat = ft_atoi_philo(av[3]);
	g_data.time_to_sleep = ft_atoi_philo(av[4]);
	g_data.time_must_eat = -1;
	g_data.msg = sem_open("msg", O_CREAT | O_EXCL, 0644, 1);
	g_data.forks = sem_open("forks", O_CREAT | O_EXCL, 0644, g_data.ph_number);
	g_data.lunch = sem_open("lunch", O_CREAT | O_EXCL, 0644, g_data.ph_number / 2);
	if (ac == 6)
		g_data.time_must_eat = ft_atoi_philo(av[5]);
	return (EXIT_SUCCESS);
}
