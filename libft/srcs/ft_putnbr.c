/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:16:10 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/03 14:27:22 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr(int n)
{
	int		count;
	int		ret;
	long	num;

	count = 0;
	num = n;
	if (num < 0)
	{
		ret = ft_putchar('-');
		if (ret == -1)
			return (-1);
		count += ret;
		num = -num;
	}
	if (num >= 10)
	{
		ret = ft_putnbr(num / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar((num % 10) + '0');
	if (ret == -1)
		return (-1);
	return (count += ret);
}