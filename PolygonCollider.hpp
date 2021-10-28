#ifndef POLYGONCOLLIDER_H_
#define POLYGONCOLLIDER_H_

#include "Collider.hpp"

namespace spic {
	class PolygonCollider : public Collider {
	private:
	#include "PolygonCollider_private.hpp"
	};
}

#endif // POLYGONCOLLIDER_H_