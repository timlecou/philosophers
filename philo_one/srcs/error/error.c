
#include "philo_one.h"

int     ft_error(char *str)
{
    int     index;

    index = 0;
    while (str[index] != '\0')
    {
        write(1, &str[index], 1);
        index++;
    }
    return (1);
}