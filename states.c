/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:00:09 by mman              #+#    #+#             */
/*   Updated: 2024/03/24 19:02:20 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_one(t_philo *p)
{
	int	i;

	i = ft_stamp(p);
	p->state = 1;
	p->eat_last = i;
	p->eat_current_count += 1;
	printf("%i %i is eating\n", i, p->id);
	usleep(p->data.time_to_eat * 1000);
	pthread_mutex_unlock(p->left);
	pthread_mutex_unlock(p->right);
	ft_two(p);
}

void	ft_two(t_philo *p)
{
	printf("%i %i is sleeping\n", ft_stamp(p), p->id);
	usleep((int)p->data.time_to_sleep * 1000);
}

void	ft_three(t_philo *p)
{
	p->state = 3;
	printf("%i %i is thinking\n", ft_stamp(p), p->id);
	pthread_mutex_lock(p->left);
	pthread_mutex_lock(p->right);
	ft_one(p);
}

void	*ft_deaththread(void *arg)
{
	t_philo	*guy;
	int		id;

	guy = (t_philo *)arg;
	id = guy->id;
	while (guy->state != 0)
	{
		if (ft_stamp(guy) - guy->eat_last >= guy->data.time_to_die)
		{
			printf("%i %i died\n", ft_stamp(guy), guy->id);
			guy->state = 0;
			exit(EXIT_SUCCESS);
		}
		if (guy->eat_current_count == guy->data.max_optional_count)
			exit(EXIT_SUCCESS);
	}
}
