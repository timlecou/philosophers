/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 10:45:07 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/20 15:20:02 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_print(int n, int id, char *str, t_data *data)
{
	if (data->stop == 1)
		return ;
	pthread_mutex_lock(&data->msg);
	ft_putnbr(n);
	ft_putstr(" ");
	ft_putnbr(id);
	ft_putstr(str);
	pthread_mutex_unlock(&data->msg);
}

long	get_time(void)
{
	struct timeval  tp;
	long			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

void	take_forks(t_data *data, int id)
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
			id + 1, " has taken a fork\n", data);
			ft_print((int)(get_time() - data->start_time),
			id + 1, " has taken a fork\n", data);
			break ;
		}
	}
}

int		eat(t_data *data, int id)
{
	pthread_mutex_lock(&data->eat[id]);
	ft_print((int)(get_time() - data->start_time),
	id + 1, " is eating\n", data);
	ft_usleep(data->time_to_eat * 1000);
	data->ph[id].has_eat = 1;
	data->ph[id].eat_count++;
	data->ph[id].r_fork = 0;
	data->ph[id].l_fork = 0;
	data->ph[data->ph[id].l_neigh].r_fork = 0;
	data->ph[data->ph[id].r_neigh].l_fork = 0;
	data->ph[id].has_fork = 0;
	if (data->stop == 1)
		return (1) ;
	pthread_mutex_unlock(&data->forks[id]);
	pthread_mutex_unlock(&data->forks[data->ph[id].r_neigh]);
	pthread_mutex_unlock(&data->eat[id]);
	return (0);
}

void	*start_routine(void *d)
{
	t_data	  *data;
	int		 id;

	data = (t_data*)d;
	id = data->index;
	init_neighs(data, id);
	while (1)
	{
		if (data->stop == 1)
			break ;
		take_forks(data, id);
		data->ph[id].last_time_eat = get_time();
		if (eat(data, id))
			break ;
		ft_print((int)(get_time() -
		data->start_time), id + 1, " is sleeping\n", data);
		ft_usleep(data->time_to_sleep * 1000);
		if (data->ph[i].eat_count == data->time_must_eat)
		{
			data->fed = 1;
			break ;
		}
		if (data->stop == 1)
			break ;
		ft_print((int)(get_time() -
		data->start_time), id + 1, " is thinking\n", data);
	}
	data->number--;
	return (NULL);
}
//assurer que l'ordre des etapes est respecte

int	death_routine(t_data *data)
{
	int i;
	long time;
	long current_time;

	i = 0;
	time = 0;
	current_time = 0;
	while (i < data->ph_number)
	{
		if (data->ph[i].has_eat == 1)
		{
			time = get_time() - data->ph[i].last_time_eat;
			if (time > data->time_to_die)
			{
				pthread_mutex_lock(&data->eat[i]);
				ft_print((int)(get_time()
				- data->start_time), i + 1, " died\n", data);
				data->stop = 1;
				data->number--;
				return (-1);
			}
		}
	}
	return (0);
}

int	init_mutex(t_data *data)
{
	int i;

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
		i++;
	}
	return (EXIT_SUCCESS);
}

int	launch_philo(t_data *data)
{
	int	 i;

	i = 0;
	if (init_mutex(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (i < data->ph_number)
	{
		data->index = i;
		if (pthread_create(&data->ph[i].thread, NULL, start_routine, (void*)data) == -1)
			return (EXIT_FAILURE);
		pthread_detach(data->ph[i].thread);
		usleep(10);
		i += 2;
	}
	i = 1;
	ft_usleep(5000);
	while (i < data->ph_number)
	{
		data->index = i;
		if (pthread_create(&data->ph[i].thread, NULL, start_routine, (void*)data) == -1)
			return (EXIT_FAILURE);
		pthread_detach(data->ph[i].thread);
		usleep(10);
		i += 2;
	}
	while (death_routine(data) == 0)
		;
	return (EXIT_SUCCESS);
}

void	wait_all_philo_to_finish(t_data *data)
{
	while (data->number > 1)
		;
}

int		main(int ac, char **av)
{
	t_data  data;

	data = init_data_struct();
	data.start_time = get_time();
	if (ac != 5 && ac != 6)
		return (ft_error("wrong number of arguments\n"));
	if (ft_parsing(&data, ac, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (launch_philo(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	wait_all_philo_to_finish(&data);
	return (EXIT_SUCCESS);
}
