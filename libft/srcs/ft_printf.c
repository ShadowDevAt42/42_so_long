/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:18:59 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/03 14:19:44 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	handle_pointer(void *ptr)
{
	int	count;
	int	ret;

	count = 0;
	if (ptr == NULL)
	{
		ret = ft_putstr("0x0");
		if (ret == -1)
			return (-1);
		count += ret;
	}
	else
	{
		ret = ft_putstr("0x");
		if (ret == -1)
			return (-1);
		count += ret;
		ret = ft_puthex((unsigned long)ptr, 0);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	return (count);
}

int	handle_conversion(char specifier, va_list *args)
{
	int	count;
	int	ret;

	count = 0;
	if (specifier == 'c')
		ret = ft_putchar(va_arg(*args, int));
	else if (specifier == 's')
		ret = ft_putstr(va_arg(*args, char *));
	else if (specifier == 'p')
		ret = handle_pointer(va_arg(*args, void *));
	else if (specifier == 'd' || specifier == 'i')
		ret = ft_putnbr(va_arg(*args, int));
	else if (specifier == 'u')
		ret = ft_putunsigned(va_arg(*args, unsigned int));
	else if (specifier == 'x')
		ret = ft_puthex(va_arg(*args, unsigned int), 0);
	else if (specifier == 'X')
		ret = ft_puthex(va_arg(*args, unsigned int), 1);
	else if (specifier == '%')
		ret = ft_putchar('%');
	else
		ret = ft_putchar(specifier);
	if (ret == -1)
		return (-1);
	return (count += ret);
}

static int	process_format(const char **format, va_list *args)
{
	int	ret;

	if (**format == '%')
	{
		(*format)++;
		if (**format)
		{
			ret = handle_conversion(**format, args);
			if (ret == -1)
				return (-1);
			(*format)++;
			return (ret);
		}
		return (0);
	}
	ret = ft_putchar(**format);
	if (ret == -1)
		return (-1);
	(*format)++;
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		ret;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		ret = process_format(&format, &args);
		if (ret == -1)
		{
			va_end(args);
			return (-1);
		}
		count += ret;
	}
	va_end(args);
	return (count);
}