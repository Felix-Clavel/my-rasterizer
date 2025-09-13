#include "math/Vecteur.hpp"

class Camera {
    private:
        Vecteur position;
        Vecteur lookat;
        Vecteur up;
        Vecteur right;

        float nearPlane;
        float farPlane;
        float aspectRatio;
        float fov;

    public:
        Camera(); // TODO: implement
};