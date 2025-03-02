#include "event_controller.hpp"

void EventController::registerListener(const std::string& event, Callback callback) {
    listeners[event].push_back(callback);
}

void EventController::raiseEvent(const std::string& event, const std::vector<int>& args) {
    if (listeners.find(event) != listeners.end()) {
        for (auto& callback : listeners[event]) {
            callback(args);
        }
    }
}
