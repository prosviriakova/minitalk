/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:02:16 by oprosvir          #+#    #+#             */
/*   Updated: 2024/03/07 17:33:03 by oprosvir         ###   ########.fr       */
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
	if (bit_count == 8)
	{
		write(1, &current_char, 1);
		bit_count = 0;
		current_char = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s_sigact;

	ft_printf("Server PID: %d\n", getpid());
	ft_printf("Press [CTRL+C] to stop server\n");
	ft_printf("----------------------------\n");
	s_sigact.sa_flags = SA_SIGINFO;
	s_sigact.sa_sigaction = handle_signal;
	sigemptyset(&s_sigact.sa_mask);
	sigaction(SIGUSR1, &s_sigact, NULL);
	sigaction(SIGUSR2, &s_sigact, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
