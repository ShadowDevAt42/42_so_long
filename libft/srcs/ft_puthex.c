/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:16:56 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/03 14:27:19 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_puthex(unsigned long n, int uppercase)
{
	int		count;
	int		ret;
	char	*hex_digits;

	count = 0;
	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (n >= 16)
	{
		ret = ft_puthex(n / 16, uppercase);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar(hex_digits[n % 16]);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}