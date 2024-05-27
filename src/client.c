/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:01:49 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/27 23:02:49 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "minitalk.h"

static int	g_ack_received = 0;

void	handle_ack(int signum)
{
	(void)signum;
	g_ack_received = 1;
}

void	send_char(int server_pid, char c)
{
	int	bit;

	bit = 0;
	signal(SIGUSR1, handle_ack);
	while (bit < 8)
	{
		g_ack_received = 0;
		if (c & (1 << bit))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (!g_ack_received)
			usleep(10);
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*msg;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [Server PID] [String to send]\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0 || server_pid > 99998)
	{
		ft_printf("ERROR: Invalid PID: %d\n", server_pid);
		exit(EXIT_FAILURE);
	}
	if (kill(server_pid, 0) < 0)
	{
		ft_printf("ERROR: Failed to send signal to PID: %d\n", server_pid);
		exit(EXIT_FAILURE);
	}
	msg = argv[2];
	while (*msg)
	{
		send_char(server_pid, *msg);
		msg++;
	}
	send_char(server_pid, '\n');
	exit(EXIT_SUCCESS);
}
