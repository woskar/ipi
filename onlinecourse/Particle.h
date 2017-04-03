#ifndef PARTICLE_H
#define PARTICLE_H

#include <stdlib.h>

struct Particle {
    // Position of Particles
    double m_x;
    double m_y;

    Particle()
    {
        m_x = ((2.0 * rand()) / RAND_MAX)-1;
        m_y = ((2.0 * rand()) / RAND_MAX)-1;
    }


};

#endif
