/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:06:34 by mman              #+#    #+#             */
/*   Updated: 2024/03/24 19:14:58 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/time.h>
# include <errno.h>
# include <stdbool.h>


# define MAX_PHILOSOPHERS 900

typedef struct s_data
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_optional_count;
	size_t			time_start;
}		t_data;

typedef struct s_philo
{
	int				state;
	int				id;
	size_t			eat_last;
	pthread_t		thread;
	pthread_t		death;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_optional_count;
	int				eat_current_count;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	**forks;
	t_data			data;
}	t_philo;

size_t	ft_get_current_time(void);
int		ft_stamp(t_philo *p);
int		ft_util_lfork(int position, int count);
void	ft_param_check(int argc, char *argv[]);
void	ft_mutex_init(pthread_mutex_t **forks, int count);
void	ft_mutex_destroy(pthread_mutex_t **forks, int count);
void	ft_one(t_philo *p);
void	ft_two(t_philo *p);
void	ft_three(t_philo *p);
void	*ft_thread(void *arg);
void	*ft_deaththread(void *arg);
void	ft_program(int count, int argc, char *argv[], pthread_mutex_t **forks);
int		ft_isnum(const char *str);

#endif
