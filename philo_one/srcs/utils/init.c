/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:06:33 by timlecou          #+#    #+#             */
/*   Updated: 2020/02/11 03:45:38 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_one.h"

t_data  init_data_struct(void)
{
    t_data  data;

    data.ph_number = 0;
    data.time_must_eat = 0;
    data.time_to_die = 0;
    data.time_to_eat = 0;
    data.time_to_sleep = 0;
    return (data);
}

void init_t_philo(t_data *data, int id)
{
    data->ph[id].id = id;
    data->ph[id].thread = 0;
}
