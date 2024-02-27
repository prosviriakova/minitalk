/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:01:49 by oprosvir          #+#    #+#             */
/*   Updated: 2024/02/27 23:01:49 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <Server PID>\n", argv[0]);
        return 1;
    }

    // Преобразуем PID из аргумента командной строки
    int server_pid = atoi(argv[1]);

    // Отправляем сигнал серверу
    if (kill(server_pid, SIGUSR1) == -1) {
        perror("Error sending signal");
        return 1;
    }

    return 0;
}
