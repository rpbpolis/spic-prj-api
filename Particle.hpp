#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "Color.hpp"
#include "Vector2.hpp"

namespace spic {
	struct Particle {
		Vector2 Gravity;
		float RadialAcceleration;
		float RadialAccelerationVar;
		float Speed;
		float SpeedVar;
		int Angle;
		int AngleVar;
		float Life;
		float LifeVar;
		float StartSize;
		float StartSizeVar;
		float EndSize;
		float EndSizeVar;
		float EmissionRate;
		Color StartColor;
		Color EndColor;
		Vector2 EmissionArea;
	};
}

#endif // PARTICLE_H_