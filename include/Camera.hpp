#include "math/Vec3.hpp"
#include "math/Mat4.hpp"

class Camera {
    private:
        Vec3 position;
        Vec3 lookat;
        Vec3 up;
        Vec3 right;

        float nearPlane;
        float farPlane;
        float aspectRatio;
        float fov;

    public:

        // TODO ya mieux ou pas ?
        Camera() {
            position = Vec3(0.0f, 0.0f, 5.0f);
            lookat = Vec3(0.0f, 0.0f, 0.0f);
            up = Vec3(0.0f, 1.0f, 0.0f);
            right = Vec3(1.0f, 0.0f, 0.0f);

            nearPlane = 0.1f;
            farPlane = 100.0f;
            aspectRatio = 4.0f / 3.0f;
            fov = 90.0f;
        };
        
        Camera(const Vec3& position, const Vec3& lookat, const Vec3& up, const Vec3& right, float nearPlane, float farPlane, float aspectRatio, float fov)
            : position(position), lookat(lookat), up(up), right(right), nearPlane(nearPlane), farPlane(farPlane), aspectRatio(aspectRatio), fov(fov) {};
        

        Mat4 getViewMatrix() {
            Mat4 rotation({
                right.getX(), right.getY(), right.getZ(), 0,
                up.getX(), up.getY(), up.getZ(), 0,
                lookat.getX(), lookat.getY(), lookat.getZ(), 0,
                0, 0, 0, 1
            });

            Mat4 translation({
                1, 0, 0, -position.getX(),
                0, 1, 0, -position.getY(),
                0, 0, 1, -position.getZ(),
                0, 0, 0, 1
            });

            return rotation * translation;
        }

        // TODO fov en radian ?
        Mat4 getProjMatrix() {
            return Mat4::perspective(fov * (3.14159265f / 180.0f), aspectRatio, nearPlane, farPlane);
        }
};