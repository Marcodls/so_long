/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-aless <md-aless@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:39:58 by md-aless          #+#    #+#             */
/*   Updated: 2022/04/04 15:39:59 by md-aless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_animation(t_data *v)
{
	static int	x;

	if (x > 3)
		x = 0;
	if (ft_delay(&v->delay1, 1800) == 1)
		return ;
	mlx_put_image_to_window(v->mlx, v->win,
		v->img[14 + x], v->j * 64, v->i * 64);
	x += 1;
}

void	coin_animation(t_data *v)
{
	int			i;
	int			j;
	static int	x;

	i = -1;
	if (x > 5)
		x = 0;
	if (ft_delay(&v->delay, 1500) == 1)
		return ;
	while (++i < v->height)
	{
		j = -1;
		while (++j < v->width)
		{
			if (v->matrix[i][j] == 'C')
			{
				mlx_put_image_to_window(v->mlx, v->win,
					v->img[8 + x], j * 64, i * 64);
			}
		}
	}
	x += 1;
}

void	check_monster(t_data *v)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	k = 0;
	l = 0;
	v->mstr_arr = malloc(sizeof(int *) * v->monsters);
	while (i < v->height)
	{
		j = 0;
		while (v->matrix[i][j] != '\0')
		{
			if (v->matrix[i][j] == 'M')
			{
				v->mstr_arr[k] = malloc(sizeof(int) * 2);
				v->mstr_arr[k][l] = i;
				v->mstr_arr[k][l + 1] = j;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	mstr_move(t_data *v)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while (v->monsters > k)
	{
		v->mstr_y = v->mstr_arr[k][l];
		v->mstr_x = v->mstr_arr[k][l + 1];
		if (v->end == 0)
			find_route(v, k);
		k++;
	}
}

int	loop_animation(t_data *v)
{
	if (v->end == 0 && v->trigger_start != 0 && v->winner == 0)
	{
		coin_animation(v);
		player_animation(v);
		if (v->loop++ < 5000)
			return (0);
		v->loop = 0;
		mstr_move(v);
	}
	return (0);
}
