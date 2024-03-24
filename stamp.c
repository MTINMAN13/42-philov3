/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:01:30 by mman              #+#    #+#             */
/*   Updated: 2024/03/24 19:01:41 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_stamp(t_philo *p)
{
	return ((int)(ft_get_current_time() - p->data.time_start));
}
