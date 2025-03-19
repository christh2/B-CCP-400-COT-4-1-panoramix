/*
** EPITECH PROJECT, 2024
** pano
** File description:
** main file
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "../include/gaulois.h"
#include "../include/druide.h"
#include "../include/marmite.h"

void print_usage(char *p_name)
{
    printf("USAGE: %s <nb_villagers> "
    "<pot_size> <nb_fights> <nb_refills>\n", p_name);
    printf("Values must be >0.\n");
}

void init_marmi_et_semaph(int pot_size)
{
    initialize_marmite(pot_size);
    sem_init(&refill_sem, 0, 0);
    sem_init(&full_sem, 0, 0);
}

void cr_threads_join(int nb_villagers, int nb_fights, int nb_refills)
{
    druide_t *druide = create_druide(nb_refills);
    gaulois_t *gaulois;
    pthread_t gaulois_threads[nb_villagers];

    pthread_create(&druide->thread_id, NULL,
    druide_behavior, (void *)druide);
    for (int i = 0; i < nb_villagers; i++) {
        gaulois = create_gaulois(i, nb_fights);
        pthread_create(&gaulois_threads[i], NULL,
        gaulois_behavior, (void *)gaulois);
    }
    for (int i = 0; i < nb_villagers; i++) {
        pthread_join(gaulois_threads[i], NULL);
    }
    destroy_druide(druide);
    sem_destroy(&refill_sem);
    sem_destroy(&full_sem);
}

int main(int argc, char *argv[])
{
    int nb_villagers = atoi(argv[1]);
    int pot_size = atoi(argv[2]);
    int nb_fights = atoi(argv[3]);
    int nb_refills = atoi(argv[4]);

    if (argc != 5) {
        print_usage(argv[0]);
        return 84;
    }
    if (nb_villagers <= 0 || pot_size <= 0
        || nb_fights <= 0 || nb_refills <= 0) {
        print_usage(argv[0]);
        return 84;
    }
    init_marmi_et_semaph(pot_size);
    cr_threads_join(nb_villagers, nb_fights, nb_refills);
    return 0;
}
