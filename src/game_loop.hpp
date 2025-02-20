#ifndef GAME_LOOP_HPP
#define GAME_LOOP_HPP

#include "controller.hpp"
#include <vector>

class GameLoop {
public:
    GameLoop() = default;
    ~GameLoop() = default;

    void start(){
        is_running = true;
        float delta_time = 0.016f;  // 60 FPS
        while (is_running){
            update(delta_time);
        }
    }

    void stop(){
        is_running = false;
    }

    void update(float delta){
        for (auto* controller : controllers){
            controller->update();
        }
    }

    void registerController(Controller* controller){
        controllers.push_back(controller);
    }

    void unregisterController(Controller* controller){
        auto it = std::remove(controllers.begin(), controllers.end(), controller);
        if (it != controllers.end()){
            controllers.erase(it, controllers.end());
        }
    }

private:
    bool is_running = false;
    std::vector<Controller*> controllers;
};

#endif // !GAME_LOOP_HPP
