/*
 name: bolinha.cpp
 compiling: g++ -std=c++17 bolinha.cpp -o bolinha -lncurses
*/
#include <ncurses.h>
#include <thread>
#include <chrono>

int main() {
    // Inicializa ncurses
    initscr();              // Inicia modo ncurses
    cbreak();               // Desativa buffering de linha
    noecho();               // Não ecoa caracteres digitados
    keypad(stdscr, TRUE);   // Habilita captura de teclas especiais
    nodelay(stdscr, TRUE);  // getch() não bloqueia
    curs_set(0);            // Oculta cursor

    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);

    int x = 1, y = 1;
    int dx = 1, dy = 1;

    while (true) {
        // Lê tecla (ou ERR se não houver)
        int ch = getch();
        if (ch == 'q' || ch == 27 /* ESC */) {
            break;
        }

        // Apaga bolinha anterior
        mvaddch(y, x, ' ');

        // Atualiza posição
        x += dx;
        y += dy;

        // Verifica colisão com as bordas
        if (x <= 0 || x >= max_x - 1) dx = -dx;
        if (y <= 0 || y >= max_y - 1) dy = -dy;

        // Desenha nova bolinha
        mvaddch(y, x, '*');

        // Força ncurses a redesenhar a tela
        refresh();

        // Pequena pausa para suavizar o movimento
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    // Restaura terminal ao estado normal
    curs_set(1);
    endwin();
    return 0;
}
