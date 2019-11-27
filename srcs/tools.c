/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:25:47 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/27 12:47:09 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	skip_line(int fd)
{
	char *str;

	get_next_line(fd, &str);
	free(str);
}

void	anchor_token(t_token *token, int i)
{
	int		x;
	int		y;

	x = TX(i);
	y = TY(i);
	i = 0;
	while (i < token->cnt_tiles)
	{
		TX(i) -= x;
		TY(i) -= y;
		i++;
	}
}

void	ft_log(char *msg, ...)
{
	va_list	args;
	FILE	*log_file;
	
	log_file = fopen("jn_log.txt", "a+");
	va_start(args, msg);
	vfprintf(log_file, msg, args);
	fflush(log_file);
	va_end(args);
	fclose(log_file);
}

void	reset_game(t_map *map, t_token *token)
{
	int i;

	i = 0;
	ft_bzero((void*)token, sizeof(t_token)); /*free strings and shit*/
	while (i < map->lines)
	{
		if (map->map[i])
			ft_strdel(&map->map[i]);
		i++;
	}
	map->map = NULL;
	map->lines = 0;
	map->columns = 0;
	map->my_area = 0;
	map->enemy_area = 0;
}