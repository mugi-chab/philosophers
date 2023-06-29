/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:46:24 by svillalv          #+#    #+#             */
/*   Updated: 2023/06/29 17:44:30 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
# define NC	"\e[0m"
# define YELLOW	"\e[1;33m"
# define BYELLOW	"\e[1;33m"
# define RED	"\e[31m"
# define GREEN "\e[32m"
# define TIMES_TO_COUNT 21000

typedef struct s_philo
{
	int				id;
	int				state;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*eat_mutex;
} t_philo;

typedef struct	s_philo_args
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_philos;
	int				num_of_eats;
} t_philo_args;

typedef	struct s_counter
{
	pthread_mutex_t	count_mutex;
	unsigned int	count;
} t_counter;

// args
int	ft_check_args(int ac, char **av);
int ft_atoi(const char *str);

#endif