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

typedef struct  s_philo
{
    int         id;
    pthread_t   thread;
}               t_philo;

typedef struct  s_data
{
    int         ph_number;
    int         time_to_eat;
    int         time_to_sleep;
    int         time_to_die;
    int         time_must_eat;
    t_philo     *ph;
}               t_data;
#endif
