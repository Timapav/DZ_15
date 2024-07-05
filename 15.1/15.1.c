#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Пользовательский обработчик сигнала для SIGUSR1
void handle_sigusr1(int signum) {
    // Проверяем, что сигнал именно SIGUSR1
    if (signum == SIGUSR1) { 
        printf("Программа получила SIGUSR1!\n");  
    }
}

int main() {
    struct sigaction sa;

    // Настраиваем структуру sigaction для определения нового обработчика
    sa.sa_handler = handle_sigusr1;  // Указываем функцию-обработчик
    sa.sa_flags = 0;  // Без дополнительных флагов
    sigemptyset(&sa.sa_mask);  // Очищаем маску сигналов

    // Устанавливаем новый обработчик для SIGUSR1
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {  // Если произошла ошибка
        perror("sigaction");  
        exit(EXIT_FAILURE);  // Завершаем программу с кодом ошибки
    }

    
    while (1) {
        pause();  
    }

    return 0;
}
