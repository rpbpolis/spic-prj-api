#ifndef EVENT_H_
#define EVENT_H_

#include "EventType.hpp"
#include "Vector2.hpp"
#include "Input.hpp"
#include "Collider.hpp"

namespace spic {
	namespace Events {
		struct Event {
			bool Handled;
			virtual EventType GetEventType();
		};

		struct MouseEvent : public Event {
			spic::Vector2 Position;
			spic::MouseButton Button;
			bool IsPressed;
		};

		struct CollisionEvent : public Event {
			spic::Collider& Collider;
			spic::Collider& OtherCollider;
		};

		struct KeyEvent : public Event {
			spic::KeyCode Key;
			bool IsPressed;
		};
	}
}

#endif // EVENT_H_