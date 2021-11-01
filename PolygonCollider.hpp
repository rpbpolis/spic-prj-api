#ifndef POLYGONCOLLIDER_H_
#define POLYGONCOLLIDER_H_

#include <vector>
#include "Collider.hpp"

namespace spic {
	class PolygonCollider : public Collider {
	public:
		PolygonCollider(std::vector<Vector2> points, std::vector<int> collideLayers, Vector2 offset) : Collider(collideLayers, offset);
		void AddPoint(Vector2 newPoint);
	private:
	#include "PolygonCollider_private.hpp"
	};
}

#endif // POLYGONCOLLIDER_H_