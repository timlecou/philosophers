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

void    take_forks(t_data *data, int id)
{
    while (data->ph[id].has_fork == 0)
    {
        pthread_mutex_lock(&data->forks);
        if (data->ph[id].r_fork == 0 && data->ph[id].l_fork == 0)
        {
            data->ph[id].r_fork = 1;
            data->ph[id].l_fork = 1;
            data->ph[data->ph[id].l_neigh].r_fork = 1;
            data->ph[data->ph[id].r_neigh].l_fork = 1;
            printf("%ld %d has taken a fork\n", get_time() - data->start_time, id + 1);
            printf("%ld %d has taken a fork\n", get_time() - data->start_time, id + 1);
            data->ph[id].has_fork = 1;
        }
        pthread_mutex_unlock(&data->forks);
        if (data->ph[id].has_fork == 1)
        {
            printf("%ld %d is eating\n", get_time() - data->start_time, id + 1);
            break ;
        }
    }
}

void    eat(t_data *data, int id)
{
    ft_usleep(data->time_to_eat * 1000);
    data->ph[id].last_time_eat = get_time();
    printf("--[%d]-- a mangé\n");
    data->ph[id].has_eat = 1;
    data->ph[id].r_fork = 0;
    data->ph[id].l_fork = 0;
    data->ph[data->ph[id].l_neigh].r_fork = 0;
    data->ph[data->ph[id].r_neigh].l_fork = 0;
    data->ph[id].has_fork = 0;
}

void    *start_routine(void *d)
{
    t_data      *data;
    int         id;

    data = (t_data*)d;
    id = data->index;
    init_neighs(data, id);
    while (1)
    {
        take_forks(data, id);
        eat(data, id);
        printf("%ld %d is sleeping\n", get_time() - data->start_time, id + 1);
        ft_usleep(data->time_to_sleep * 1000);
        printf("%ld %d is thinking\n", get_time() - data->start_time, id + 1);
    }
    return (NULL);
}

void    *death_routine(void *d)
{
    t_data      *data;
    int         i;
    long        time;

    data = (t_data*)d;
    i = 0;
    time = 0;
    while (1)
    {
        i = 0;
        while (i < data->ph_number)
        {
            if (data->ph[i].has_eat == 1)
            {
                time = get_time() - data->ph[i].last_time_eat;
                if (time > data->time_to_die)
                {
                    printf("time = %ld\n", time);
                    printf("%ld %d died\n", get_time() - data->start_time, i + 1);
                    exit(EXIT_SUCCESS);
                }
            }
            i++;
        }
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
        data->index = i;
        if (pthread_create(&data->ph[i].thread, NULL, start_routine, (void*)data) == -1)
            return ;
        usleep(10);
        i++;
    }
    if (pthread_create(&data->d_th, NULL, death_routine, (void*)data) == -1)
        return ;
    i = 0;
    while (i < data->ph_number)
    {
        pthread_join(data->ph[i].thread, NULL);
        i++;
    }
    pthread_join(data->d_th, NULL);
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