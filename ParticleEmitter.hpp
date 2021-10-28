#ifndef PARTICLEEMITTER_H_
#define PARTICLEEMITTER_H_

#include "Component.hpp"

namespace spic {
	class ParticleEmitter : public Component {
	public:
		void Play();
		void Stop();
	private:
	#include "ParticleEmitter_private.hpp"
	};
}

#endif // PARTICLEEMITTER_H_