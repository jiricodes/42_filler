/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 09:31:19 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/03 17:19:09 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** If looking for parallel vector through point A then the point B
** on such vector can be found by:
** B.x = A.x - main_v.direction.x;
** B.y = A.y - main_v.direction.y;
*/

void		main_vector(t_map *map)
{
	t_coords mine;
	t_coords enemy;

	find_mine(map, &mine);
	map->right.edge = mine;
	map->left.edge = mine;
	find_enemy(map, &enemy);
	map->right.crit_max = enemy;
	map->right.crit_min = enemy;
	map->left.crit_max = enemy;
	map->left.crit_min = enemy;
	map->main_v.start = mine;
	map->main_v.direction = get_direction(&mine, &enemy);
}

t_coords	get_direction(t_coords *start, t_coords *point)
{
	t_coords direction;

	direction.x = start->x - point->x;
	direction.y = start->y - point->y;
	return (direction);
}

void		get_deltas(t_token *token)
{
	int i;
	int j;

	token->v_delta = 0;
	token->h_delta = 0;
	i = 0;
	while (i < token->cnt_tiles)
	{
		j = i + 1;
		while (j < token->cnt_tiles)
		{
			if (token->tiles[j].x - token->tiles[i].x > token->h_delta)
				token->h_delta = token->tiles[j].x - token->tiles[i].x;
			if (token->tiles[j].y - token->tiles[i].y > token->v_delta)
				token->v_delta = token->tiles[j].y - token->tiles[i].y;
			j++;
		}
		i++;
	}
}