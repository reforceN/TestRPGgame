#include <windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void stc(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
