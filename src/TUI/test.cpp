#include <ncurses.h>

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    // Check if terminal supports color
    if (!has_colors()) {
        endwin();
        printf("Your terminal does not support color\n");
        return 1;
    }

    // Enable color support
    start_color();

    // Check if color pairs are supported
    if (!can_change_color() || COLORS < 4 || COLOR_PAIRS < 4) {
        endwin();
        printf("Your terminal does not support enough color pairs\n");
        return 1;
    }

    // Define color pairs
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);

    //Create windows
    int height = LINES / 2; // Divide screen height by 2
    int width = COLS / 2;   // Divide screen width by 2

    // Create windows with colored background
    WINDOW *win1 = newwin(height, width, 0, 0);                      // Top-left window
    wbkgd(win1, COLOR_PAIR(1));
    WINDOW *win2 = newwin(height, width, 0, width);                  // Top-right window
    wbkgd(win2, COLOR_PAIR(2));
    WINDOW *win3 = newwin(height, width, height, 0);                 // Bottom-left window
    wbkgd(win3, COLOR_PAIR(3));
    WINDOW *win4 = newwin(height, width, height, width);             // Bottom-right window
    wbkgd(win4, COLOR_PAIR(4));

    // Print text in each window
    mvwprintw(win1, height / 2, width / 2 - 4, "Window 1");
    mvwprintw(win2, height / 2, width / 2 - 4, "Window 2");
    mvwprintw(win3, height / 2, width / 2 - 4, "Window 3");
    mvwprintw(win4, height / 2, width / 2 - 4, "Window 4");

    // Refresh windows
    wrefresh(win1);
    wrefresh(win2);
    wrefresh(win3);
    wrefresh(win4);

    // Wait for user input
    getch();

    // Clean up
    delwin(win1);
    delwin(win2);
    delwin(win3);
    delwin(win4);
    endwin();

    return 0;
}
 
