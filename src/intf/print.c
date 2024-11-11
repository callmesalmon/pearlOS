#include "print.h"

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct Char {
    uint8_t character;
    uint8_t color;
};

struct Char* buffer = (struct Char*) 0xb8000;
size_t col    = 0;
size_t row    = 0;
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;

void clearRow(size_t row) {
    struct Char empty = (struct Char) {
        .character =  ' ',
        .color     = color,
    };

    for (size_t col = 0; col < NUM_COLS; col++) {
        buffer[col + NUM_COLS * row] = empty;
    }
}

void printClear() {
    for (size_t i = 0; i < NUM_ROWS; i++) {
        clearRow(i);
    }
}

void printNewline() {
    col = 0;

    if (row < NUM_ROWS - 1) {
        row++;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; row++) {
        for (size_t col = 0; col < NUM_COLS; col++) {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clearRow(NUM_COLS - 1);
}

void printChar(char character) {
    if (character == '\n') {
        printNewline();
        return;
    }

    if (col > NUM_COLS) {
        printNewline();
    }

    buffer[col + NUM_COLS * row] = (struct Char) {
        .character = (uint8_t) character,
        .color = color,
    };

    col++;
}

void printStr(char* str) {
    for (size_t i = 0; 1; i++) {
        char character = (uint8_t) str[i];

        if (character == '\0') {
            return;
        }

        printChar(character);
    }
}

void printSetColor(uint8_t foreground, uint8_t background) {
    color = foreground + (background << 4);
}
