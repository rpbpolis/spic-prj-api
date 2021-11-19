#ifndef BANJO_GAME_EVENTBUS_HPP
#define BANJO_GAME_EVENTBUS_HPP

#include <eventbus/event_bus.hpp>
#include <map>

namespace spic {
    class EventBus {
    public:
        EventBus();

        template <typename T> unsigned long Listen(std::function<void(const T&)> fn) {
            handlers.template try_emplace(++handlerId, eventBus.register_handler<T>(fn));
            return handlerId;
        }

        template <typename T, typename... Args> void Publish(Args&&... args) {
            eventBus.fire_event(T{std::forward<Args>(args)...});
        }

        void Unregister(unsigned long);

    private:
        dp::event_bus eventBus;

        unsigned long handlerId;
        std::map<unsigned long, dp::handler_registration> handlers;
    };
}

#endif
