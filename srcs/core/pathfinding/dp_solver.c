/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:22:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 12:47:45 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

int	tsp_dp(int **dist, int nb_nodes)
{
	t_dp_state	state;
	int			mask;
	int			best;

	init_dp_state(&state, dist, nb_nodes);
	if (!state.dp)
		return (-1);
	init_base_cases(state.dp, dist, state.num_collect);
	mask = -1;
	while (++mask <= state.all_mask)
		process_state(&state, mask);
	best = find_best_path(&state);
	cleanup_matrix(state.dp, state.all_mask + 1);
	if (best == MAX_INT)
		return (-1);
	return (best);
}
