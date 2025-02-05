/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:17:27 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/04 23:49:48 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_fd_list
{
	int					fd;
	char				*data;
	size_t				len;
	size_t				capacity;
	struct s_fd_list	*next;
}	t_fd_list;

//ft_printf
int	ft_printf(const char *format, ...);
int	handle_conversion(char specifier, va_list *args);
int	handle_pointer(void *ptr);

//Gnl
char		*get_next_line(int fd);
int			ft_append_buffer(t_fd_list *node, char *data, size_t data_len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
t_fd_list	*ft_get_fd_node(t_fd_list **head, int fd);
void		ft_remove_fd_node(t_fd_list **head, int fd);

//Libft
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned int n);
int	ft_puthex(unsigned long n, int uppercase);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);

#endif