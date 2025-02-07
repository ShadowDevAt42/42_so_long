/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:22:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 12:22:36 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static int	**init_dp_array(int all_mask, int num_collect)
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

static void	init_base_cases(int **dp, int **dist, int num_collect)
{
	int	i;

	i = 0;
	while (++i <= num_collect)
		if (dist[0][i] != -1)
			dp[1 << (i - 1)][i] = dist[0][i];
}

static void	process_state(int **dp, int **dist, int mask,
	int num_collect)
{
	int	i;
	int	j;
	int	next_mask;

	i = 0;
	while (++i <= num_collect)
	{
		if (!(mask & (1 << (i - 1))))
			continue ;
		j = 0;
		while (++j <= num_collect)
		{
			if (mask & (1 << (j - 1)))
				continue ;
			next_mask = mask | (1 << (j - 1));
			if (dp[mask][i] != MAX_INT && dist[i][j] != -1)
				dp[next_mask][j] = ft_min(dp[next_mask][j],
						dp[mask][i] + dist[i][j]);
		}
	}
}

static int	find_best_path(int **dp, int **dist, int all_mask,
	int num_collect, int nb_nodes)
{
	int	best;
	int	i;

	best = MAX_INT;
	i = 0;
	while (++i <= num_collect)
		if (dp[all_mask][i] != MAX_INT && dist[i][nb_nodes - 1] != -1)
			best = ft_min(best, dp[all_mask][i] + dist[i][nb_nodes - 1]);
	return (best);
}

int	tsp_dp(int **dist, int nb_nodes)
{
	int	num_collect;
	int	all_mask;
	int	**dp;
	int	mask;
	int	best;

	num_collect = nb_nodes - 2;
	all_mask = (1 << num_collect) - 1;
	dp = init_dp_array(all_mask, num_collect);
	if (!dp)
		return (-1);
	init_base_cases(dp, dist, num_collect);
	mask = -1;
	while (++mask <= all_mask)
		process_state(dp, dist, mask, num_collect);
	best = find_best_path(dp, dist, all_mask, num_collect, nb_nodes);
	cleanup_matrix(dp, all_mask + 1);
	if (best == MAX_INT)
		return (-1);
	return (best);
}
