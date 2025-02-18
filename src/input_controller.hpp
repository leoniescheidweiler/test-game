#ifndef INPUT_CONTROLLER_HPP
#define INPUT_CONTROLLER_HPP

#include "controller.hpp"
#include <iostream>

class InputController : public Controller {
public:
    InputController() = default;
    ~InputController() = default;

    // Override the update method from Controller
    void update() override{
        pollInput();
    }

    void pollInput(){
        std::cout << "Polling Input..." << std::endl;

        if (isKeyPressed('W')){
            std::cout << "Move forward!" << std::endl;
        }

        if (isKeyPressed('A')){
            std::cout << "Move left!" << std::endl;
        }
    }

    bool isKeyPressed(char key){
        // Simulating key press check
        return key == 'W' || key == 'A';
    }

private:
    
};

#endif // !INPUT_CONTROLLER_HPP
