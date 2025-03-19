/*
** EPITECH PROJECT, 2024
** pano
** File description:
** main file
*/

#pragma once

#include <pthread.h>

typedef struct {
    pthread_t thread_id;
    int nb_refills;
    int pot_size;
} druide_t;

druide_t *create_druide(int nb_refills);
void destroy_druide(druide_t *druide);
void *druide_behavior(void *arg);
