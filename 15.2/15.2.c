#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    sigset_t newmask;  // Создаем набор сигналов

    // Инициализируем набор сигналов как пустой
    sigemptyset(&newmask);

    // Добавляем SIGINT в набор сигналов
    sigaddset(&newmask, SIGINT);

    // Блокируем SIGINT
    if (sigprocmask(SIG_BLOCK, &newmask, NULL) == -1) {  // Если произошла ошибка
        perror("sigprocmask");  
        exit(EXIT_FAILURE);  
    }

    // Сообщаем, что SIGINT теперь заблокирован
    printf("SIGINT теперь заблокирован. Нажатие Ctrl+C не завершит эту программу.\n");

    
    while (1) {
        pause();  
    }

    return 0;
}
