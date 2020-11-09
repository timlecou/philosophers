/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:06:33 by timlecou          #+#    #+#             */
/*   Updated: 2020/01/11 15:06:38 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct      s_philo
{
    int             id;
    int             r_fork;
    int             l_fork;
    int             has_fork;
    long            last_time_eat;
    int             has_eat;
    pthread_t       thread;
    int             r_neigh;
    int             l_neigh;
}                   t_philo;

typedef struct      s_data
{
    int             ph_number;
    int             time_to_eat;
    int             time_to_sleep;
    int             time_to_die;
    int             time_must_eat;
    int             index;
    t_philo         *ph;
    long            start_time;
    pthread_t       d_th;
    pthread_mutex_t forks;
}                   t_data;
#endif
