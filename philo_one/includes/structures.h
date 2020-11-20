/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 10:43:04 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/20 16:19:25 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct		s_philo
{
	pthread_t		thread;
	int				id;
	int				has_fork;
	long			last_time_eat;
	int				has_eat;
	int				r_fork;
	int				l_fork;
	int				r_neigh;
	int				l_neigh;
	int				fed;
	int				eat_count;
}					t_philo;

typedef struct		s_data
{
	int				index;
	int				stop;
	int				all_fed;
	int				number;
	int				ph_number;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				time_must_eat;
	t_philo			*ph;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg;
	pthread_mutex_t	*eat;
}					t_data;
#endif
