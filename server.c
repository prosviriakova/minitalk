/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:02:16 by oprosvir          #+#    #+#             */
/*   Updated: 2024/02/29 00:31:24 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int signal) {
    static int bit_count = 0;
    static char current_char = 0;

    if (signal == SIGUSR1) {
        current_char <<= 1;
    } else if (signal == SIGUSR2) {
        current_char = (current_char << 1) | 1;
    }

    bit_count++;
    if (bit_count == 8) {
        write(1, &current_char, 1);
        bit_count = 0;
        current_char = 0;
    }
}

int main() {
    printf("Welcome To Olga's Server!\n");
    printf("Server PID: %d\n", getpid());    

    while (1) {
        signal(SIGUSR1, handle_signal);
        signal(SIGUSR2, handle_signal);
        pause(); // Ожидаем сигнал
    }

    return (0);
}
