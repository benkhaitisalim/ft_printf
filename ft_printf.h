/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:54:57 by bsalim            #+#    #+#             */
/*   Updated: 2024/11/22 12:02:10 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putcharachter(char intger, int *counter);
void	ft_putstring(char *string, int *counting);
void	ft_putnumber(int number, int *pointer);
void	ft_puthexadecimalower(unsigned long long nbrhexa, int *pointer);
void	ft_putpointer(void *ptr, int *lenth);
void	ft_putunsignedint(unsigned int number, int *suiver);
int		ft_printf(const char *mendatory, ...);
void	ft_puthexadecimaupper(unsigned int nbrhexa, int *pointer);

#endif