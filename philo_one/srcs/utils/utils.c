/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:06:33 by timlecou          #+#    #+#             */
/*   Updated: 2020/12/11 13:56:38 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_one.h"

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

int     ft_atoi_philo(char *str)
{
    int	i;
    int	res;

    i = 0;
    res = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
           || str[i] == '\v' || str[i] == '\f' || str[i] == '\n')
        i++;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] <= '9' && str[i] >= '0')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res);
}