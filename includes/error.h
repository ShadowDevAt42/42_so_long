/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 02:10:10 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 18:14:40 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "struc.h"

void	handle_error(t_error error_code);
char	*get_error_message(t_error error_code);
void	handle_error_with_info(t_error error_code, t_error_info *error_info);

#endif
