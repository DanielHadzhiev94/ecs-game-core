#pragma once

#include <typeindex>
#include <unordered_map>
#include <vector>
#include <functional>

namespace engine::core
{
    class EventBus
    {
    public:
        template <typename Event>
        using Listener = std::function<void(const Event &)>;

        template <typename Event>
        void subscribe(Listener<Event> listener)
        {
            auto wrapper = [listener](const void *eventPtr)
            {
                listener(static_cast<const Event *>(eventPtr));
            };

            listeners[typeid(Event)].push_back(wrapper);
        }

        template <typename Event>
        void publish(const Event &event)
        {
            auto it = listeners.find(typeid(Event));
            if (it == listeners.end())
                return;

            for (auto &listener : it->second)
            {
                listener(&event);
            }
        };

    private:
        std::unordered_map<
            std::type_index,
            std::vector<std::function<void(const void *)>>>
            listeners;
    };

}