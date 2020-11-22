/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:06:33 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/22 12:16:14 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_data  init_data_struct(void)
{
    t_data  data;

    data.ph_number = 0;
    data.number = 0;
    data.all_fed = 0;
    data.time_must_eat = 0;
    data.time_to_die = 0;
    data.time_to_eat = 0;
    data.time_to_sleep = 0;
    data.start_time = 0;
    data.index = 0;
    data.die = 0;
    return (data);
}

void    init_t_philo(t_data *data, int id)
{
    data->ph[id].id = id;
    data->ph[id].thread = 0;
    data->ph[id].death_thread = 0;
    data->ph[id].has_fork = 0;
    data->ph[id].last_time_eat = 0;
    data->ph[id].has_eat = 0;
    data->ph[id].r_neigh = 0;
    data->ph[id].l_neigh = 0;
	data->ph[id].eat_count = data->time_must_eat;
}

void       init_neighs(t_data *data, unsigned int id)
{
    if (id == 0)
        data->ph[id].r_neigh = data->ph_number - 1;
    else
        data->ph[id].r_neigh = id - 1;
    if (id == data->ph_number - 1)
        data->ph[id].l_neigh = 0;
    else
        data->ph[id].l_neigh = id + 1;
}

int	init_mutex(t_data *data)
{
	unsigned int i;

	i = 0;
	if (!(data->forks = malloc(sizeof(pthread_mutex_t) * data->ph_number)))
		return (EXIT_FAILURE);
	if (!(data->eat = malloc(sizeof(pthread_mutex_t) * data->ph_number)))
		return (EXIT_FAILURE);
	pthread_mutex_init(&data->msg, NULL);
	while (i < data->ph_number)
	{
		pthread_mutex_init(&data->eat[i], NULL);
		pthread_mutex_init(&data->forks[i], NULL);
		++i;
	}
	return (EXIT_SUCCESS);
}
