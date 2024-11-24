/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordsandcharachter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 07:22:32 by bsalim            #+#    #+#             */
/*   Updated: 2024/11/24 16:43:30 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_putcharachter(char charachter, int *count)
{
	write(1, &charachter, 1);
	(*count)++;
}

void	ft_putstring(char *string, int *counting)
{
	int	index;

	index = 0;
	if (!string)
	{
		write(1, "(null)", 6);
		*counting += 6;
		return ;
	}
	while (string[index])
	{
		ft_putcharachter(string[index], counting);
		index++;
	}
}
