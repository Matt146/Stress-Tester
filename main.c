#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BLOAT_FILE "bloatme.txt"

typedef unsigned long long uint64_t;

void bloat_drive(uint64_t bytes) {
    FILE* fp = fopen(BLOAT_FILE, "w");
    char* zero_initializer = (char*)"0";
    for (uint64_t i = 0; i < bytes; i++) {
        fprintf(fp, "%s", zero_initializer);
    }
}

char* read_file(uint64_t buffsize) {
    char* buffer = (char*)malloc(sizeof(char) * buffsize);
    FILE* fp = fopen(BLOAT_FILE, "r");
    if (fp == NULL) {
        printf("[Error] Bloat file does not exist!\n");
        printf("[Info] Creating new bloat file with 2^18 bytes!\n");
    }
    uint64_t indexer = 0;
    char char_getter;
    while (!feof(fp)) {
        char_getter = getc(fp);
        buffer[indexer] = char_getter;
        indexer++;
    }
    fclose(fp);
    buffer[indexer] = '\0';
    return buffer;    
}

void eat(uint64_t bytes) {
    bool isRunning = true;
    char** bloat_buffer = (char**)malloc(sizeof(char) * bytes);
    for (uint64_t i = 0; i < bytes; i++) {
        bloat_buffer[i] = (char*)malloc(sizeof(char) * bytes);
    }
    uint64_t indexer = 0;
    while (isRunning) {
        bloat_buffer[indexer] = read_file(bytes);
        indexer++;
    }
}

int main(int argc, char** argv) {
    bool isRunning = true;
    while (isRunning == true) {
        printf("Arguments: %lld, %lld\n", strtoll(argv[1], NULL, 0), strtoll(argv[2], NULL, 0));
        printf("[Stage] Starting Stage 1 - Drive Bloat!\n");
        printf("[Info] Bloating drive!\n");
        bloat_drive(strtoll(argv[1], NULL, 0));
        printf("[Info] Drive bloated!");
        printf("[Stage] Starting Stage 2- Memory Eating!\n");
        eat(strtoll(argv[2], NULL, 0));
        printf("[Info] Memory bloated!\n");
        printf("[Info] Execution finished!\n");
        printf("[Info] Exiting!\n");
    }
    return 0;
}