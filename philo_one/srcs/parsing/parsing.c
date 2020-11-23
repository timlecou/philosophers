/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:06:33 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/23 12:06:45 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

extern	t_data	g_data;

int    ft_parsing(int ac, char **av)
{
    unsigned int     i;

    i = 0;
    g_data.ph_number = ft_atoi_philo(av[1]);
    g_data.time_to_die = ft_atoi_philo(av[2]);
    g_data.time_to_die = ft_atoi_philo(av[2]);
    g_data.number = g_data.ph_number;
    g_data.time_to_eat = ft_atoi_philo(av[3]);
    g_data.time_to_sleep = ft_atoi_philo(av[4]);
    g_data.time_must_eat = -1;
    if (ac == 6)
	{
        g_data.time_must_eat = ft_atoi_philo(av[5]);
    	//g_data.number = g_data.ph_number;
	}
    return (EXIT_SUCCESS);
}
