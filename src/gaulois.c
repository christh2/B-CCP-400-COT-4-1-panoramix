/*
** EPITECH PROJECT, 2024
** pano
** File description:
** main file
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "../include/gaulois.h"
#include "../include/marmite.h"

gaulois_t *create_gaulois(int id, int nb_fights)
{
    gaulois_t *gaulois = (gaulois_t *)malloc(sizeof(gaulois_t));

    if (gaulois != NULL) {
        gaulois->id = id;
        gaulois->nb_fights = nb_fights;
    }
    return gaulois;
}

void simulate_combat(gaulois_t *gaulois, int fight_number)
{
    pthread_mutex_unlock(&marmite_mutex);
    printf("Villager %d: Take that roman scum! Only %d left.\n",
    gaulois->id, gaulois->nb_fights - fight_number - 1);
    sleep(1);
}

void *gaulois_behavior(void *arg)
{
    gaulois_t *gaulois = (gaulois_t *)arg;

    printf("Villager %d: Going into battle!\n", gaulois->id);
    for (int i = 0; i < gaulois->nb_fights; i++) {
        printf("Villager %d: I need a drink... I see %d servings left.\n",
        gaulois->id, marmite.nb_servings);
        pthread_mutex_lock(&marmite_mutex);
        if (marmite.nb_servings == 0) {
            printf("Villager %d: Hey Pano wake up! We need more potion.\n",
            gaulois->id);
            sem_post(&refill_sem);
            sem_wait(&full_sem);
        }
        marmite.nb_servings--;
        simulate_combat(gaulois, i);
    }
    printf("Villager %d: I'm going to sleep now.\n", gaulois->id);
    free(gaulois);
    pthread_exit(NULL);
}
