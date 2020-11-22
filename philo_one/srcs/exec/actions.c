/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:47:24 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/22 11:31:23 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	take_forks(t_data *data, unsigned int id)
{
	while (data->ph[id].has_fork == 0)
	{
		if (data->ph[id].r_fork == 0 && data->ph[id].l_fork == 0)
		{
			pthread_mutex_lock(&data->forks[id]);
			pthread_mutex_lock(&data->forks[data->ph[id].r_neigh]);
			data->ph[id].r_fork = 1;
			data->ph[id].l_fork = 1;
			data->ph[data->ph[id].l_neigh].r_fork = 1;
			data->ph[data->ph[id].r_neigh].l_fork = 1;
			data->ph[id].has_fork = 1;
		}
		if (data->ph[id].has_fork == 1)
		{
			ft_print((int)(get_time() - data->start_time),
			id + 1, FORK, data);
			ft_print((int)(get_time() - data->start_time),
			id + 1, FORK, data);
			break ;
		}
	}
}

int		eat(t_data *data, int id)
{
	ft_print((int)(get_time() - data->start_time),
	id + 1, EATING, data);
	ft_usleep(data->time_to_eat * 1000);
	data->ph[id].has_eat = 1;
	data->ph[id].eat_count++;
	data->ph[id].r_fork = 0;
	data->ph[id].l_fork = 0;
	data->ph[data->ph[id].l_neigh].r_fork = 0;
	data->ph[data->ph[id].r_neigh].l_fork = 0;
	data->ph[id].has_fork = 0;
	pthread_mutex_unlock(&data->forks[id]);
	pthread_mutex_unlock(&data->forks[data->ph[id].r_neigh]);
	return (0);
}
