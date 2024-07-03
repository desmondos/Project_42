/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:25:56 by candriam          #+#    #+#             */
/*   Updated: 2024/06/23 15:46:57 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_set	set;

	set.map_filepath = argv[1];
	main_input(&set);
	if (argc != 2)
		puterror("usage: ./fdf <map.fdf or filepath>");
	if (is_fdf_ext(set.map_filepath))
	{
		map_info(&set, set.map_filepath);
		check_map(&set, set.map_filepath);
		parsing(&set, set.map_filepath);
		x_y_z_dim(&set);
		init_set(&set, argv[1]);
	}
	else
		puterror("wrong or missing extension");
	while (1)
		;
}
