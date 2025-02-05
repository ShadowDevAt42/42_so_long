/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:15:29 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/03 14:27:26 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putstr(char *str)
{
	int	count;
	int	ret;

	count = 0;
	if (str == NULL)
	{
		ret = write(1, "(null)", 6);
		if (ret == -1)
			return (-1);
		return (6);
	}
	while (*str)
	{
		ret = ft_putchar(*str);
		if (ret == -1)
			return (-1);
		count += ret;
		str++;
	}
	return (count);
}