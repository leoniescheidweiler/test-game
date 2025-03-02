#ifndef DEBUG_CONTROLLER_HPP
#define DEBUG_CONTROLLER_HPP

#include "controller.hpp"
#include "event_controller.hpp"

class DebugController : public Controller {
    public:
    DebugController(EventController& eventController);
    ~DebugController() = default;

    void update() override {};

    private:
    EventController& eventController;
    void onAnyEvent(const std::vector<int>& args);
};

#endif  // !DEBUG_CONTROLLER_HPP
