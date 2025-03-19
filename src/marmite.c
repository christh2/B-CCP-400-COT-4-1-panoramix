/*
** EPITECH PROJECT, 2024
** pano
** File description:
** main file
*/

#include "../include/marmite.h"
#include <stdlib.h>
#include <stdio.h>

marmite_t marmite = {.nb_servings = MARMITE_SIZE};
pthread_mutex_t marmite_mutex = PTHREAD_MUTEX_INITIALIZER;

sem_t refill_sem;
sem_t full_sem;

marmite_t *create_marmite(int nb_servings)
{
    marmite_t *marmite = (marmite_t *)malloc(sizeof(marmite_t));

    if (marmite != NULL) {
        marmite->nb_servings = nb_servings;
    }
    return marmite;
}

void destroy_marmite(marmite_t *marmite)
{
    if (marmite != NULL) {
        free(marmite);
    }
}

void initialize_marmite(int pot_size)
{
    marmite.nb_servings = pot_size;
}
