/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:02:45 by mman              #+#    #+#             */
/*   Updated: 2024/03/24 19:03:23 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_program(int count, int argc, char *argv[], pthread_mutex_t **forks)
{
	t_philo		*philo_data;
	pthread_t	checker;
	t_data		data;
	int			buff;

	data.time_to_die = atoi(argv[2]);
	data.time_to_eat = atoi(argv[3]);
	data.time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		data.max_optional_count = atoi(argv[5]);
	else
		data.max_optional_count = -1;
	data.time_start = ft_get_current_time();
	buff = 0;
	philo_data = malloc(sizeof(t_philo) * count);
	while (buff < count)
	{
		philo_data[buff].data = data;
		philo_data[buff].state = 3;
		philo_data[buff].id = buff + 1;
		philo_data[buff].eat_last = 0;
		philo_data[buff].eat_current_count = 0;
		philo_data[buff].left = forks[ft_util_lfork(buff, count)];
		philo_data[buff].right = forks[buff % (count - 1)];
		pthread_create(&philo_data[buff].thread, NULL,
			ft_thread, &philo_data[buff]);
		pthread_create(&philo_data[buff].death, NULL,
			ft_deaththread, &philo_data[buff]);
		usleep(300);
		buff++;
	}
	buff--;
	while (buff >= 0)
	{
		// join a thread
		pthread_join(philo_data[buff].thread, NULL);
		buff--;
	}
	//free stuff at the end
	ft_cleanup(philo_data);
	printf("\nClean Exit 1\n");
}
