/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:06:33 by timlecou          #+#    #+#             */
/*   Updated: 2020/02/11 03:45:38 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

long    get_time(void)
{
    struct timeval  tp;
    long            milliseconds;

    gettimeofday(&tp, NULL);
    milliseconds = tp.tv_sec * 1000;
    milliseconds += tp.tv_usec / 1000;
    return (milliseconds);
}

void    take_forks(t_data *data)
{
    int id;

    id = data->index;
    pthread_mutex_lock(&data->forks);
    data->ph[id].has_fork = 0;
    if (data->ph[id].r_fork == 0 && data->ph[id].l_fork == 0)
    {
        data->ph[id].r_fork = 1;
        data->ph[id].l_fork = 1;
        data->ph[((id == 0) ? data->ph_number : id + 1)].r_fork = 1;
        data->ph[((id == data->ph_number) ? 0 : id - 1)].l_fork = 1;
        printf("%ld %d has taken a fork\n", get_time() - data->start_time, id);
        printf("%ld %d has taken a fork\n", get_time() - data->start_time, id);
        data->ph[id].has_fork = 1;
    }
    pthread_mutex_unlock(&data->forks);
    if (data->ph[id].has_fork == 1)
        printf("%ld %d is eating\n", get_time() - data->start_time, id);
}

void    *start_routine(void *d)
{
    t_data      *data;

    data = (t_data*)d;
    while (1)
    {
        take_forks(data);
        usleep(data->time_to_eat * 1000);
        data->ph[data->index].r_fork = 0;
        data->ph[data->index].l_fork = 0;
        data->ph[((data->index == 0) ? data->ph_number : data->index + 1)].r_fork = 0;
        data->ph[((data->index == data->ph_number) ? 0 : data->index - 1)].l_fork = 0;
        printf("%ld %d is sleeping\n", get_time() - data->start_time, data->index);
        usleep(data->time_to_sleep * 1000);
        printf("%ld %d is thinking\n", get_time() - data->start_time, data->index);
    }
    return (NULL);
}

void    launch_philo(t_data *data)
{
    int     i;

    i = 0;
    pthread_mutex_init(&data->forks, NULL);
    while (i < data->ph_number)
    {
        data->index = i + 1;
        if (pthread_create(&data->ph[i].thread, NULL, start_routine, (void*)data) == -1)
            return ;
        //pthread_join(data->ph[i].thread, NULL);
        pthread_detach(data->ph[i].thread);
        usleep(10);
        i++;
    }
}

int main(int ac, char **av)
{
    t_data  data;

    data = init_data_struct();
    data.start_time = get_time();
    if (ac == 5 || ac == 6)
    {
        if (ft_parsing(&data, ac, av) == EXIT_FAILURE)
            return (1);
        launch_philo(&data);
    }
    return (0);
}