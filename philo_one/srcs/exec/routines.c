/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:45:23 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/22 12:23:13 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		everyone_fed(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->ph_number)
	{
		if (data->ph[i].fed == 0)
			return (0);
		++i;
	}
	data->all_fed = 1;
	return (1);
}

void	*start_routine(void *d)
{
	t_data	  *data;
	int		 id;

	data = (t_data*)d;
	id = data->index;
	init_neighs(data, id);
	while (!data->die)
	{
		take_forks(data, id);
		pthread_mutex_lock(&data->eat[id]);
		data->ph[id].last_time_eat = get_time();
		pthread_mutex_unlock(&data->eat[id]);
		eat(data, id);
		if (data->ph[id].eat_count == 0)
			break ;
		ft_print((int)(get_time() -
		data->start_time), id + 1, SLEEPING, data);
		ft_usleep(data->time_to_sleep * 1000);
		ft_print((int)(get_time() -
		data->start_time), id + 1, THINKING, data);
	}
	data->number--;
	return (NULL);
}

void	*death_routine(void *d)
{
	t_data			*data;
	unsigned int	i;
	long 			time;

	data = (t_data*)d;
	i = data->index;
	time = 0;
	while (!data->die)
	{
		if (data->ph[i].has_eat == 1)
		{
			pthread_mutex_lock(&data->eat[i]);
			time = get_time() - data->ph[i].last_time_eat;
			if (time > data->time_to_die || data->ph[i].eat_count == 0)
			{
				if (!data->die && data->ph[i].eat_count != 0)
				{
					data->die = 1;
					ft_print((int)(get_time()
					- data->start_time), i + 1, DIED, data);
				}
				pthread_mutex_unlock(&data->eat[i]);
				return (NULL);
			}
			pthread_mutex_unlock(&data->eat[i]);
			usleep(4000);
		}
	}
	return (NULL);
}
