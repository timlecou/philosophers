/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:06:33 by timlecou          #+#    #+#             */
/*   Updated: 2020/12/11 13:56:38 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_one.h"

int    ft_parsing(t_data *data, int ac, char **av)
{
    int     i;

    i = -1;
    data->ph_number = ft_atoi_philo(av[1]);
    data->time_to_die = ft_atoi_philo(av[2]);
    data->time_to_eat = ft_atoi_philo(av[3]);
    data->time_to_sleep = ft_atoi_philo(av[4]);
    if (!(data->ph = malloc(sizeof(t_philo) * data->ph_number)))
        return (EXIT_FAILURE);
    while (++i < data->ph_number)
        init_t_philo(data, i);
    if (ac == 6)
        data->time_must_eat = ft_atoi_philo(av[5]);
    return (EXIT_SUCCESS);
}