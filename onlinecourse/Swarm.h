#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

class Swarm {
public:
    const static int NPARTICLES = 3000;

private:
    Particle * m_pParticles;

public:
    Swarm()
    {
        m_pParticles = new Particle[NPARTICLES];
    }

    ~Swarm()
    {
        delete[] m_pParticles;
    }

    const Particle * const getParticles()
    {
        return m_pParticles;
    }

};

#endif
