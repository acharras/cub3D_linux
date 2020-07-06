/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:16:09 by acharras          #+#    #+#             */
/*   Updated: 2020/06/08 18:50:03 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int			key_input(int key, t_cub3d *game)
{
	game->key = key;
	if (game->key == 65307)
		ft_exit(game);
	if (game->key == 65361)
		game->left_arrow = 1;
	if (game->key == 65363)
		game->right_arrow = 1;
	if (game->key == 97)
		game->press_a = 1;
	if (game->key == 100)
		game->press_d = 1;
	if (game->key == 115)
		game->press_s = 1;
	if (game->key == 119)
		game->press_w = 1;
	if (game->key == 65505)
		game->press_shift = 1;
	if (game->key == 104)
		game->press_h++;
	return (1);
}

int			key_release(int key, t_cub3d *game)
{
	game->key = key;
	if (game->key == 65361)
		game->left_arrow = 0;
	if (game->key == 65363)
		game->right_arrow = 0;
	if (game->key == 97)
		game->press_a = 0;
	if (game->key == 100)
		game->press_d = 0;
	if (game->key == 115)
		game->press_s = 0;
	if (game->key == 119)
		game->press_w = 0;
	if (game->key == 65505)
		game->press_shift = 0;
	return (1);
}
