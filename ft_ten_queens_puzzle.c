/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:50:45 by hboudar           #+#    #+#             */
/*   Updated: 2023/09/02 16:34:42 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	prints(int board[10][10], int *count)
{
	int	i;
	int	j;
	int	q;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			if (board[j][i])
			{
				q = j + 48;
				write(1, &q, 1);
			}
		}
	}
	write(1, "\n", 1);
	*count = *count + 1;
}

int	isqsafe(int board[10][10], int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < col)
		if (board[row][i++])
			return (0);
	i = row;
	j = col;
	while (i >= 0 && j >= 0)
		if (board[i--][j--])
			return (0);
	i = row;
	j = col;
	while (i < 10 && j >= 0)
		if (board[i++][j--])
			return (0);
	return (1);
}

void	placeq(int board[10][10], int col, int *count)
{
	int	i;

	if (col == 10)
	{
		prints(board, count);
	}
	i = -1;
	while (++i < 10)
	{
		if (isqsafe(board, i, col))
		{
			board[i][col] = 1;
			placeq(board, col + 1, count);
			board[i][col] = 0;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10][10];
	int	i;
	int	j;
	int	*count;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			board[i][j] = 0;
	}
	i = 0;
	count = &i;
	placeq(board, 0, count);
	return (i);
}
