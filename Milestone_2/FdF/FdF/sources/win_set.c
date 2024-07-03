/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:00:36 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 15:02:00 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_win(t_set *set)
{
	mlx_destroy_window(set->mlx, set->win);
	exit(EXIT_SUCCESS);
}

int	key_press(int keycode, t_set *set)
{
	if (keycode == 65307)
		close_win(set);
	map_rotate(keycode, set);
	move_all_dir(keycode, set);
	altitude(keycode, set);
	set_map_color_dyn(keycode, set);
	set_bg_color_dyn(keycode, set);
	set_map_brightness(keycode, set);
	return (0);
}

void	all_hook(t_set *set)
{
	mlx_key_hook(set->win, key_press, set);
	mlx_hook(set->win, 17, 0, close_win, set);
	mlx_hook(set->win, 4, 1L << 2, mouse_zoom, set);
	mlx_hook(set->win, 2, 1L << 0, key_press, set);
}
