/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:48:44 by bsalim            #+#    #+#             */
/*   Updated: 2024/11/24 17:07:59 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_the_format(char specifier, va_list *args, int *lenth,
		int *index)
{
	if (specifier == 's')
		ft_putstring(va_arg(*args, char *), lenth);
	else if (specifier == 'd')
		ft_putnumber(va_arg(*args, int), lenth);
	else if (specifier == 'c')
		ft_putcharachter(va_arg(*args, int), lenth);
	else if (specifier == 'u')
		ft_putunsignedint(va_arg(*args, int), lenth);
	else if (specifier == 'X')
		ft_puthexadecimaupper(va_arg(*args, unsigned int), lenth);
	else if (specifier == 'x')
		ft_puthexadecimalower(va_arg(*args, unsigned int), lenth); 
	else if (specifier == 'i')
		ft_putnumber(va_arg(*args, int), lenth);
	else if (specifier == 'p')
		ft_putpointer(va_arg(*args, void *), lenth);
	else if (specifier == '%')
		ft_putcharachter('%', lenth);
	else
		(*index)--;
}

int	ft_printf(const char *mendatory, ...)
{
	va_list	args;
	int		index;
	int		lenth;

	va_start(args, mendatory);
	lenth = 0;
	index = 0;
	if (write(1, 0, 0) < 0)
		return (-1);
	while (mendatory[index] != '\0')
	{
		if (mendatory[index] == '%')
		{
			index++;
			get_the_format(mendatory[index], &args, &lenth, &index);
			index++;
		}
		else
		{
			ft_putcharachter((char)mendatory[index], &lenth);
			index++;
		}
	}
	va_end(args);
	return (lenth);
}


// int main()
// {
//     int    ft;
//     int og;
//     int *n;

//     n = 0;
//     ft = ft_printf("inti: %i\n", 12348);
//     og = printf("inti: %i\n", 12348);
//     printf("\n");
//     ft += ft_printf("intd: %d\n", -144845);
//     og += printf("intd: %d\n", -144845);
//     ft_printf("\n");
//     ft += ft_printf("intd: %d\n", -144845);
//     og += printf("intd: %d\n", -144845);
//     printf("\n");
//     ft += ft_printf("str: %s\n", "Hello, world");
//     og += printf("str: %s\n", "Hello, world");
//     ft_printf("\n");
//     ft += ft_printf("char: %c\n", 'p');
//     og += printf("char: %c\n", 'p');
//     printf("\n");
//     ft += ft_printf("hex: %x\n", 5);
//     og += printf("hex: %x\n", 5);
//     ft_printf("\n");
//     ft += ft_printf("heX: %x\n", 255);
//     og += printf("heX: %x\n", 255);
//     ft_printf("\n");
//     ft += ft_printf("ptr: %p\n", &n);
//     og += printf("ptr: %p\n", &n);
//     printf("\n");
//     ft_printf("\n");
//     printf("OG: %d\nME: %d", og, ft);

//     return (0);
// }