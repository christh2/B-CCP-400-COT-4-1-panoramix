/*
** EPITECH PROJECT, 2024
** pano
** File description:
** main file
*/

#include "../include/druide.h"
#include "../include/marmite.h"
#include <stdlib.h>
#include <stdio.h>

druide_t *create_druide(int nb_refills)
{
    druide_t *druide = (druide_t *)malloc(sizeof(druide_t));

    if (druide != NULL) {
        druide->nb_refills = nb_refills;
    }
    return druide;
}

void destroy_druide(druide_t *druide)
{
    if (druide != NULL) {
        free(druide);
    }
}

void *druide_behavior(void *arg)
{
    druide_t *druide = (druide_t *)arg;

    printf("Druid: I'm ready... but sleepy...\n");
    while (druide->nb_refills > 0) {
        sem_wait(&refill_sem);
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it!"
        "Beware I can only make %d"
        "more refills after this one.\n", druide->nb_refills - 1);
        marmite.nb_servings = MARMITE_SIZE;
        sem_post(&full_sem);
        druide->nb_refills--;
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    pthread_exit(NULL);
}
