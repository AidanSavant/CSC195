#pragma once

class Shape {
public:
    Shape() = default;
    virtual ~Shape() = default;

    virtual float Area() = 0;
};

