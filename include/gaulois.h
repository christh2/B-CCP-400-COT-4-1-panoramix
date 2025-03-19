/*
** EPITECH PROJECT, 2024
** pano
** File description:
** main file
*/

#pragma once

typedef struct {
    int id;
    int nb_fights;
} gaulois_t;

gaulois_t *create_gaulois(int id, int nb_fights);
void simulate_combat(gaulois_t *gaulois, int fight_number);
void *gaulois_behavior(void *arg);
