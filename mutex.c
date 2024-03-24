/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:51:31 by mman              #+#    #+#             */
/*   Updated: 2024/03/24 18:59:16 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_mutex_init(pthread_mutex_t **forks, int count)
{
	count--;
	while (count >= 0)
	{
		forks[count] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (forks[count] == 0)
			exit(EXIT_FAILURE);
		pthread_mutex_init(forks[count], NULL);
		count--;
	}
}

void	ft_mutex_destroy(pthread_mutex_t **forks, int count)
{
	count--;
	while (count >= 0)
	{
		pthread_mutex_destroy(forks[count]);
		free(forks[count]);
		count--;
	}
}
