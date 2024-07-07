/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_ok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:25:56 by candriam          #+#    #+#             */
/*   Updated: 2024/07/07 16:19:30 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		return (1);
	import_map(&fdf.map, argv[1]);
	sys_init(&fdf);
	if (draw_fdf(&fdf, SIZED) < 0)
		return (1);
	all_hooks(&fdf);
	mlx_loop(fdf.set.mlx);
	free(fdf.map.dots);
	free(fdf.map.mem);
	return (0);
}

void	sys_init(t_fdf *fdf)
{
	fdf->map.render = 0;
	fdf->map.alt = 0.4;
	fdf->map.prop = fdf->map.lim.ax[2] / fdf->map.lim.ax[0];
	if (fdf->map.prop > 0.5)
		fdf->map.divide_z = fdf->map.prop * 30;
	fdf->key.leftctrl = 0;
	fdf->key.rightctrl = 0;
	fdf->mouse.leftmouse = 0;
	fdf->mouse.rightmouse = 0;
	fdf->set.mlx = mlx_init();
	fdf->set.win = mlx_new_window(fdf->set.mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	fdf->b_map.img = mlx_new_image(fdf->set.mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->b_map.buffer = mlx_get_data_addr(fdf->b_map.img, &fdf->b_map.bpix,
									   &fdf->b_map.lines, &fdf->b_map.endi);
}

void	all_hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->set.win, key_press, fdf);
	mlx_hook(fdf->set.win, 2, 1L << 0, key_press, fdf);
	mlx_hook(fdf->set.win, 3, 0, key_release, fdf);
	mlx_hook(fdf->set.win, 4, 1L << 2, mouse_zoom, fdf);
//	mlx_hook(fdf->set.win, 5, 0, mouse_release, fdf);
//	mlx_hook(fdf->set.win, 6, 0, mouse_move, fdf);
	mlx_hook(fdf->set.win, 17, 0, exit_program, fdf);

}
