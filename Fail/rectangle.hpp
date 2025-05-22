#pragma once

#include "shape.hpp"

class Rectangle : public Shape {
public:
    Rectangle(float w, float h) {
        m_width = w;
        m_height = h;
    }
    ~Rectangle() override = default;

    float Area() override {
        return m_width * m_height;
    }

private:
    float m_width;
    float m_height;
};

