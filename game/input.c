/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:24:10 by mruizzo           #+#    #+#             */
/*   Updated: 2022/03/25 16:45:19 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_enemies(t_game *game);
void	kill_player(t_game *game);

void	move_right(t_game *game)
{
	if (game->player.tile->right->type == COLLECTABLE)
		game->collects--;
	if (game->player.tile->right->type == EXIT && game->collects == 0)
		game->status = 1;
	if (game->player.tile->right->type == ENEMY)
	{
		kill_player(game);
		return ;
	}
	if (game->player.tile->right->type != WALL
		&& game->player.tile->right->type != EXIT)
	{
		game->moves++;
		game->player.tile->right->type = PLAYER;
		game->player.tile->type = EMPTY;
		game->player.tile = game->player.tile->right;
		ft_printf("Mosse fatte --> %d \n", game->moves);
		move_enemies(game);
	}
}

void	move_left(t_game *game)
{
	if (game->player.tile->left->type == COLLECTABLE)
		game->collects--;
	if (game->player.tile->left->type == EXIT && game->collects == 0)
		game->status = 1;
	if (game->player.tile->left->type == ENEMY)
	{
		kill_player(game);
		return ;
	}
	if ((game->player.tile->left->type != WALL)
		&& game->player.tile->left->type != EXIT)
	{
		game->moves++;
		game->player.tile->left->type = PLAYER;
		game->player.tile->type = EMPTY;
		game->player.tile = game->player.tile->left;
		ft_printf("Mosse fatte --> %d \n", game->moves);
		move_enemies(game);
	}
}

void	move_up(t_game *game)
{
	if (game->player.tile->up->type == COLLECTABLE)
		game->collects--;
	if (game->player.tile->up->type == EXIT && game->collects == 0)
		game->status = 1;
	if (game->player.tile->up->type == ENEMY)
	{
		kill_player(game);
		return ;
	}
	if ((game->player.tile->up->type != WALL)
		&& game->player.tile->up->type != EXIT)
	{
		game->moves++;
		game->player.tile->up->type = PLAYER;
		game->player.tile->type = EMPTY;
		game->player.tile = game->player.tile->up;
		ft_printf("Mosse fatte --> %d \n", game->moves);
		move_enemies(game);
	}
}

void	move_down(t_game *game)
{
	if (game->player.tile->down->type == COLLECTABLE)
		game->collects--;
	if (game->player.tile->down->type == EXIT && game->collects == 0)
		game->status = 1;
	if (game->player.tile->down->type == ENEMY)
	{
		kill_player(game);
		return ;
	}
	if (game->player.tile->down->type != WALL
		&& game->player.tile->down->type != EXIT)
	{
		game->moves++;
		game->player.tile->down->type = PLAYER;
		game->player.tile->type = EMPTY;
		game->player.tile = game->player.tile->down;
		ft_printf("Mosse fatte --> %d \n", game->moves);
		move_enemies(game);
	}
}

int	input(int key, t_game *game)
{
	if (key == 2 && game->status == 0)
		move_right(game);
	else if (key == 0 && game->status == 0)
		move_left(game);
	else if (key == 13 && game->status == 0)
		move_up(game);
	else if (key == 1 && game->status == 0)
		move_down(game);
	else if (key == 53)
		end_program(game);
	return (0);
}
