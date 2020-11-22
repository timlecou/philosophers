/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:47:24 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/22 12:12:36 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	take_forks(t_data *data, unsigned int id)
{
	pthread_mutex_lock(&data->forks[id]);
	pthread_mutex_lock(&data->forks[data->ph[id].r_neigh]);
	data->ph[id].has_fork = 1;
	ft_print((int)(get_time() - data->start_time),
	id + 1, FORK, data);
	ft_print((int)(get_time() - data->start_time),
	id + 1, FORK, data);
}

int		eat(t_data *data, int id)
{
	ft_print((int)(get_time() - data->start_time),
	id + 1, EATING, data);
	ft_usleep(data->time_to_eat * 1000);
	data->ph[id].has_eat = 1;
	if (data->time_must_eat > 0)
		data->ph[id].eat_count--;
	data->ph[id].has_fork = 0;
	pthread_mutex_unlock(&data->forks[id]);
	pthread_mutex_unlock(&data->forks[data->ph[id].r_neigh]);
	return (EXIT_SUCCESS);
}
