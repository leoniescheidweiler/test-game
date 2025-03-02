#ifndef INPUT_CONTROLLER_HPP
#define INPUT_CONTROLLER_HPP

#include <SDL.h>
#include "controller.hpp"
#include "event_controller.hpp"

class InputController : public Controller {
    public:
    InputController(EventController& eventController);
    ~InputController() = default;

    void update() override { pollInput(); }

    void pollInput();

    private:
    EventController& eventController;
};

#endif  // !INPUT_CONTROLLER_HPP
