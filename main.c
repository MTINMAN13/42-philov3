/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:52:25 by mman              #+#    #+#             */
/*   Updated: 2024/03/24 19:12:19 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_param_check(int argc, char *argv[])
{
	int	count;

	count = atoi(argv[1]);
	if (count >= 10)
	{
		printf("please only 2 - 9 philosophers, thanks.");
		exit(EXIT_SUCCESS);
	}
	if (argc == 5)
	{
		atoi(argv[1]);
		atoi(argv[2]);
		atoi(argv[3]);
		atoi(argv[4]);
	}
	else if (argc == 6)
		atoi(argv[5]);
	else
	{
		printf("Please use 4 to 5 arguments; \n1 [PHILO COUNT] \n2 [TIME TO DIE]\n3 [TIME TO EAT]\n4 [TIME TO SLEEP]\n5 [EAT COUNT MAX](optional)\n\n\n");
		exit(EXIT_FAILURE);
	}
}

void	*ft_thread(void *arg)
{
	t_philo	*guy;
	int		id;

	guy = (t_philo *)arg;
	id = guy->id;
	while (1)
		ft_three(guy);
	usleep(300);
}


int	main(int argc, char *argv[])
{
	pthread_mutex_t	*forks[MAX_PHILOSOPHERS];
	int				philo_count;

	ft_param_check(argc, argv);
	philo_count = atoi(argv[1]);
	ft_mutex_init(forks, philo_count);
	ft_program(philo_count, argc, argv, forks);
	ft_mutex_destroy(forks, philo_count);
	printf("\nClean Exit 0\n");
	return (EXIT_SUCCESS);
}
