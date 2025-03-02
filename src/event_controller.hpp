#ifndef EVENT_CONTROLLER_HPP
#define EVENT_CONTROLLER_HPP

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
#include "controller.hpp"

class EventController : public Controller {
    using Callback = std::function<void(const std::vector<int>&)>;

    public:
    EventController() = default;
    ~EventController() = default;

    void update() override {};

    void registerListener(const std::string& event, Callback callback);
    void raiseEvent(const std::string& event, const std::vector<int>& args = {});

    private:
    std::unordered_map<std::string, std::vector<Callback>> listeners;
};

#endif  // !EVENT_CONTROLLER_HPP
