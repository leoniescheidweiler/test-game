#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

class Controller {
public:
    Controller() = default;
    virtual ~Controller() = default;

    virtual void update() = 0;

private:
};

#endif // !CONTROLLER_HPP
