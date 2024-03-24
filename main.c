/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:52:25 by mman              #+#    #+#             */
/*   Updated: 2024/03/24 19:30:26 by mman             ###   ########.fr       */
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
		if (!(ft_isnum(argv[1]) && ft_isnum(argv[2]) && ft_isnum(argv[3])
				&& ft_isnum(argv[4])))
		{
			printf("Please use only numbers.");
			exit(EXIT_SUCCESS);
		}
	}
	else if (argc == 6)
	{
		if (!(ft_isnum(argv[5])))
		{
			printf("Please use only numbers.");
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		printf("Please use 4 to 5 arguments; \n1 [PHILO COUNT] \n2 ");
		printf("[TIME TO DIE]\n3 [TIME TO EAT]\n4 [TIME TO SLEEP]\n5 ");
		printf("[EAT COUNT MAX](optional)\n\n\n");
		exit(EXIT_SUCCESS);
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
