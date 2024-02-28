/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:01:49 by oprosvir          #+#    #+#             */
/*   Updated: 2024/02/29 00:32:51 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void send_bit(int server_pid, int bit) {
    if (bit == 1) {
        kill(server_pid, SIGUSR2); // Отправляем SIGUSR2 для бита 1
    } else {
        kill(server_pid, SIGUSR1); // Отправляем SIGUSR1 для бита 0
    }
    usleep(1000); // Небольшая задержка
}

void send_char(int server_pid, char c) {
    int i;
    
    i = 7;
    while (i >= 0) {
        int bit = (c >> i) & 1;
        send_bit(server_pid, bit);
        i--;
    }
}

int main(int argc, char *argv[]) {
    int server_pid;
    char* message;
    int i;

    if (argc == 3)
    {
        server_pid = atoi(argv[1]);
        message = argv[2];
        i = 0;

        while (message[i] != '\0') {
            send_char(server_pid, message[i]);
            i++;
        }
    }
    else
    {
        fprintf(stderr, "Usage: %s <Server PID> <String to send>\n", argv[0]);
        return 1;
    }

    return (0);
}
