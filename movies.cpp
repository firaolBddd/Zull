#include "movies.h"

movies::movies() {
}

char* movies::getDirector() {
    return director;
}

int* movies::getDuration() {
    return &duration;
}

float* movies::getRating() {
    return &rating;
}

int movies::getType() {
    return 2;
}

