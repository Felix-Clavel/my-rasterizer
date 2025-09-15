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


        float operator()(int row, int col) const {
            return elements[row * 4 + col];
        }
        // TODO capter la diff
        float& operator()(int row, int col) {
            return elements[row * 4 + col];
        }


        Mat4 operator*(const Mat4& other) const {
            Mat4 result;
            result.elements.fill(0.0f);
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    for (int k = 0; k < 4; ++k) {
                        result(i, j) += (*this)(i, k) * other(k, j);
                    }
                }
            }
            return result;
        }

        Vec4 operator*(const Vec4& vec) const {
            Vec4 result;
            result.setX((*this)(0,0) * vec.getX() + (*this)(0,1) * vec.getY() + (*this)(0,2) * vec.getZ() + (*this)(0,3) * vec.getW());
            result.setY((*this)(1,0) * vec.getX() + (*this)(1,1) * vec.getY() + (*this)(1,2) * vec.getZ() + (*this)(1,3) * vec.getW());
            result.setZ((*this)(2,0) * vec.getX() + (*this)(2,1) * vec.getY() + (*this)(2,2) * vec.getZ() + (*this)(2,3) * vec.getW());
            result.setW((*this)(3,0) * vec.getX() + (*this)(3,1) * vec.getY() + (*this)(3,2) * vec.getZ() + (*this)(3,3) * vec.getW());
            return result;
        }

};