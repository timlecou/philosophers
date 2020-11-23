/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 10:43:04 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/23 15:52:07 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef	struct		s_data
{
	long			start_time;
	unsigned int	all_fed;
	unsigned int	number;
	unsigned int	die;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	time_must_eat;
	unsigned int	ph_number;
	sem_t			*msg;
	sem_t			*forks;
	sem_t			*lunch;
}					t_data;

typedef struct		s_philo
{
	pthread_t		thread;
	pthread_t		death_thread;
	sem_t			*eat;
	long			last_time_eat;
	char			*name;
	unsigned int	id;
	unsigned int	has_fork;
	unsigned int	has_eat;
	unsigned int	fed;
	unsigned int	eat_count;
	struct s_philo	*next;
}					t_philo;

#endif
