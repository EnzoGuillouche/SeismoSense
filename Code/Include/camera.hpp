#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct Camera {
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    float speed = 0.05f;

    Camera()
        : position(glm::vec3(0.0f, 0.0f, 3.0f)),
          front(glm::vec3(0.0f, 0.0f, -1.0f)),
          up(glm::vec3(0.0f, 1.0f, 0.0f)) {}

    glm::mat4 getViewMatrix() {
        return glm::lookAt(position, position + front, up);
    }

    void moveForward()  { position += speed * front; }
    void moveBackward() { position -= speed * front; }
    void moveLeft()     { position -= glm::normalize(glm::cross(front, up)) * speed; }
    void moveRight()    { position += glm::normalize(glm::cross(front, up)) * speed; }
    void moveUp()       { position += speed * up; }
    void moveDown()     { position -= speed * up; }
};
