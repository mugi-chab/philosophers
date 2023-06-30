/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:46:24 by svillalv          #+#    #+#             */
/*   Updated: 2023/06/30 12:28:17 by svillalv         ###   ########.fr       */
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
	int				id_philo;
	size_t			last_meal;
	pthread_t		*id_thread;
	pthread_mutex_t	forks;
	pthread_mutex_t	print_mutex;
	t_philo_args	*args;
	t_philo			*next;
} t_philo;

typedef struct	s_philo_args
{
	int				status;
	pthread_mutex_t death_mutex;
	size_t			start_time;
	int				eat_count;
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

// check args
int		ft_check_args(int ac, char **av, t_philo_args *args);
int 	ft_atoi(const char *str);
void	ft_fill_struct(int ac, char *av, t_philo_args *args);

#endif