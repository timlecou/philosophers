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

void    take_forks(int id)
{
    //attendre que les fourchettes soient dispo
}

void    *start_routine(void *d)
{
    t_philo      *philo;

    philo = (t_philo *)d;
    printf("philo [%d]\n", philo->id);
    while (1)
    {
        take_forks(philo->id);
    }
    return (NULL);
}

void    launch_philo(t_data *data)
{
    int     i;

    i = 0;
    while (i < data->ph_number)
    {
        if (pthread_create(&data->ph[i].thread, NULL, start_routine, (void*)&data->ph[i]) == -1)
            return ;
        pthread_detach(data->ph[i].thread);
        i++;
    }
}

int main(int ac, char **av)
{
    t_data  data;

    data = init_data_struct();
    if (ac == 5 || ac == 6)
    {
        if (ft_parsing(&data, ac, av) == EXIT_FAILURE)
            return (1);
        launch_philo(&data);
    }
    return (0);
}