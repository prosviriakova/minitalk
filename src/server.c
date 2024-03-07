/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:02:16 by oprosvir          #+#    #+#             */
/*   Updated: 2024/03/05 15:56:47 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "minitalk.h"

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int	bit_count = 0;
	static char	current_char = 0;
	int			client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (signum == SIGUSR1)
		current_char |= (1 << bit_count);
	bit_count++;
	kill(client_pid, SIGUSR1);
	if (bit_count == 8)
	{
		write(1, &current_char, 1);
		bit_count = 0;
		current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	ft_printf("Press [CTRL+C] to stop server\n");
	ft_printf("----------------------------\n");
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
