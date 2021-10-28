#ifndef EVENTTYPE_H_
#define EVENTTYPE_H_

namespace spic {
	namespace Event {
		enum EventType {
			None,
			WindowClose,
			WindowResize,
			KeyPressed,
			KeyDown,
			MouseButtonPressed,
			MouseButtonReleased,
			MouseMoved,
			MouseScrolled,
			Collision
		};
	}
}

#endif // EVENTTYPE_H_