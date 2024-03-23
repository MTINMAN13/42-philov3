/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:06:34 by mman              #+#    #+#             */
/*   Updated: 2024/03/23 19:33:45 by mman             ###   ########.fr       */
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
	int				state;  // 1 is eating // 2 is sleeping // 3 is thinking // 0 is dead
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

#endif
