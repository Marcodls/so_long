/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-aless <md-aless@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:40:03 by md-aless          #+#    #+#             */
/*   Updated: 2022/04/04 15:40:04 by md-aless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_win(t_data *v)
{
	v->winner = 1;
	put_map(v);
}

void	game_over(t_data *v, int i, int k)
{
	v->end = 1;
	v->matrix[i][k] = 'M';
	put_map(v);
}

int	quit(t_data *v)
{
	free(v->path);
	free(v->img);
	free_matrix(v);
	free(v->matrix);
	free_mstr_matrix(v);
	free(v->mstr_arr);
	mlx_destroy_window(v->mlx, v->win);
	exit (0);
}

int	ft_delay(int *delay, int time)
{
	if (*delay <= time)
	{
		*delay += 1;
		return (1);
	}
	*delay = 0;
	return (0);
}

void	check_gameover(t_data *v, int x, int y)
{
	v->matrix[v->i][v->j] = '0';
	return (game_over(v, v->i + x, v->j + y));
}
