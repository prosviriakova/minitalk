/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:02:16 by oprosvir          #+#    #+#             */
/*   Updated: 2024/02/27 23:02:16 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int signal) {
    // Выводим сообщение при получении сигнала
    write(1, "Signal received\n", 16);
}

int main() {
    // Выводим PID текущего процесса
    printf("Server PID: %d\n", getpid());

    // Настраиваем обработчик сигналов
    signal(SIGUSR1, handle_signal);

    // Бесконечный цикл, чтобы сервер продолжал работать
    while (1) {
        pause(); // Ожидаем сигнал
    }

    return 0;
}
