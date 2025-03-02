#ifndef INPUT_CONTROLLER_HPP
#define INPUT_CONTROLLER_HPP

#include <SDL.h>
#include "controller.hpp"
#include "event_controller.hpp"
// #include "video_controller.hpp"
// #include "world_controller.hpp"

class InputController : public Controller {
    public:
    InputController(  // WorldController& worldController,
                      // VideoController& videoController,
        EventController& eventController);
    ~InputController() = default;

    // Override the update method from Controller
    void update() override { pollInput(); }

    void pollInput();

    private:
    // WorldController& worldController;
    // VideoController& videoController;
    EventController& eventController;
};

#endif  // !INPUT_CONTROLLER_HPP
