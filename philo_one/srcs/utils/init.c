/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:06:33 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/20 15:20:38 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_data  init_data_struct(void)
{
    t_data  data;

    data.ph_number = 0;
    data.number = 0;
    data.time_must_eat = 0;
    data.time_to_die = 0;
    data.time_to_eat = 0;
    data.time_to_sleep = 0;
    data.start_time = 0;
    data.index = 0;
    data.stop = 0;
    return (data);
}

void    init_t_philo(t_data *data, int id)
{
    data->ph[id].id = id;
    data->ph[id].fed = 0;
    data->ph[id].thread = 0;
    data->ph[id].r_fork = 0;
    data->ph[id].l_fork = 0;
    data->ph[id].has_fork = 0;
    data->ph[id].last_time_eat = 0;
    data->ph[id].has_eat = 0;
    data->ph[id].r_neigh = 0;
    data->ph[id].l_neigh = 0;
	data->ph[id].eat_count = 0;
}

void       init_neighs(t_data *data, int id)
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
