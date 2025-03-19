/*
** EPITECH PROJECT, 2024
** pano
** File description:
** main file
*/

#pragma once

#include <pthread.h>
#include <semaphore.h>

#define MARMITE_SIZE 10

typedef struct {
    int nb_servings;
    pthread_mutex_t mutex;
} marmite_t;

extern marmite_t marmite;
extern pthread_mutex_t marmite_mutex;
extern sem_t refill_sem;
extern sem_t full_sem;

void initialize_marmite(int pot_size);
marmite_t *create_marmite(int nb_servings);
void destroy_marmite(marmite_t *marmite);
