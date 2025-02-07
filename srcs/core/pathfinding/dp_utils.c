/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:22:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 12:47:34 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

int	**init_dp_array(int all_mask, int num_collect)
{
	int	**dp;
	int	i;
	int	j;

	dp = malloc(sizeof(int *) * (all_mask + 1));
	if (!dp)
		return (NULL);
	i = -1;
	while (++i <= all_mask)
	{
		dp[i] = malloc(sizeof(int) * (num_collect + 1));
		if (!dp[i])
		{
			while (--i >= 0)
				free(dp[i]);
			free(dp);
			return (NULL);
		}
		j = -1;
		while (++j <= num_collect)
			dp[i][j] = MAX_INT;
	}
	return (dp);
}

void	init_base_cases(int **dp, int **dist, int num_collect)
{
	int	i;

	i = 0;
	while (++i <= num_collect)
		if (dist[0][i] != -1)
			dp[1 << (i - 1)][i] = dist[0][i];
}

void	process_state(t_dp_state *state, int mask)
{
	int	i;
	int	j;
	int	next_mask;

	i = 0;
	while (++i <= state->num_collect)
	{
		if (!(mask & (1 << (i - 1))))
			continue ;
		j = 0;
		while (++j <= state->num_collect)
		{
			if (mask & (1 << (j - 1)))
				continue ;
			next_mask = mask | (1 << (j - 1));
			if (state->dp[mask][i] != MAX_INT && state->dist[i][j] != -1)
				state->dp[next_mask][j] = ft_min(state->dp[next_mask][j],
						state->dp[mask][i] + state->dist[i][j]);
		}
	}
}

int	find_best_path(t_dp_state *state)
{
	int	best;
	int	i;

	best = MAX_INT;
	i = 0;
	while (++i <= state->num_collect)
		if (state->dp[state->all_mask][i] != MAX_INT
			&& state->dist[i][state->nb_nodes - 1] != -1)
			best = ft_min(best,
					state->dp[state->all_mask][i]
					+ state->dist[i][state->nb_nodes - 1]);
	return (best);
}

void	init_dp_state(t_dp_state *state, int **dist, int nb_nodes)
{
	state->dist = dist;
	state->nb_nodes = nb_nodes;
	state->num_collect = nb_nodes - 2;
	state->all_mask = (1 << state->num_collect) - 1;
	state->dp = init_dp_array(state->all_mask, state->num_collect);
}
