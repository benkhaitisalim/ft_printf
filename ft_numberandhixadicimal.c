/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberandhixadicimal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 07:45:42 by bsalim            #+#    #+#             */
/*   Updated: 2024/11/23 08:38:45 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnumber(int number, int *pointer)
{
	if (number == -2147483648)
	{
		ft_putstring("-2147483648", pointer);
		return ;
	}
	if (number < 0)
	{
		ft_putcharachter('-', pointer);
		ft_putnumber((-number), pointer);
		return ;
	}
	if (number < 10)
	{
		ft_putcharachter((number + '0'), pointer);
		return ;
	}
	ft_putnumber(number / 10, pointer);
	ft_putcharachter((number % 10 + '0'), pointer);
}

void	ft_puthexadecimalower(unsigned long long nbrhexa, int *pointer)
{
	char	hexachar;

	hexachar = nbrhexa % 16;
	if (nbrhexa == 0 && *pointer == 0)
	{
		ft_putcharachter('0', pointer);
		return ;
	}
	if (nbrhexa >= 16)
	{
		ft_puthexadecimalower(nbrhexa / 16, pointer);
	}
	if (hexachar < 10)
	{
		ft_putcharachter(hexachar + '0', pointer);
	}
	else
	{
		ft_putcharachter(hexachar - 10 + 'a', pointer);
	}
}

void	ft_puthexadecimaupper(unsigned int nbrhexa, int *pointer)
{
	char	hexachar;

	if (nbrhexa == 0 && *pointer == 0)
	{
		ft_putcharachter('0', pointer);
		return ;
	}
	if (nbrhexa >= 16)
	{
		ft_puthexadecimaupper(nbrhexa / 16, pointer);
	}
	hexachar = nbrhexa % 16;
	if (hexachar < 10)
	{
		ft_putcharachter(hexachar + '0', pointer);
	}
	else
	{
		ft_putcharachter(hexachar - 10 + 'A', pointer);
	}
}

void	ft_putunsignedint(unsigned int number, int *suiver)
{
	if (number >= 10)
	{
		ft_putunsignedint(number / 10, suiver);
	}
	ft_putcharachter(number % 10 + '0', suiver);
}

void	ft_putpointer(void *ptr, int *length)
{
	unsigned long long	address;

	if (!ptr)
	{
		ft_putstring("0x0", length);
		return ;
	}
	address = (unsigned long long)ptr;
	ft_putstring("0x", length);
	ft_puthexadecimalower(address, length);
}
