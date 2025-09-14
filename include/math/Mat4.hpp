#pragma once

#include "Vec4.hpp"
#include <array>
#include <cmath>




class Mat4 {
    public:
        std::array<float, 16> elements;
        
        Mat4() : elements{0} {
            for (int i = 0; i < 4; ++i) {
                elements[i * 4 + i] = 1.0f; // Identity matrix
            }
        }

        Mat4(const std::array<float, 16>& elems) : elements(elems) {}


        static Mat4 perspective(float fov, float aspect, float near, float far) {
            float s = 1.0f / tan(fov / 2.0f);
            Mat4 result;
            result.elements = {
                s / aspect, 0, 0, 0,
                0, s, 0, 0,
                0, 0, far / (far - near), -(far * near) / (far - near),
                0, 0, 1.0f, 0
            };
            return result;
        }

};