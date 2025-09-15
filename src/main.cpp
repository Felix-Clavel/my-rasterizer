#include <vector>
#include "FrameBuffer.hpp"
#include "Camera.hpp"
#include "math/Mat4.hpp"
#include "ReadObj.hpp"
#include <iostream>



int main() {
    ReadObj obj;

    if (obj.load("assets/input.obj")) {
        std::vector<Vec3> vertices = obj.getVertices();
        std::vector<std::array<int, 3>> faces = obj.getFaces();
    } else {
        std::cerr << "Failed to load OBJ file." << std::endl;
        return -1;
    }



    FrameBuffer fb(800, 600);
    fb.clear(0x000000);


    // Handle the initialization of the camera here
    Camera cam;

    Mat4 viewMatrix = cam.getViewMatrix();
    Mat4 projMatrix = cam.getProjMatrix();


    // Handle the initialization of the light here
    Camera light;

    Mat4 lightViewMatrix = light.getViewMatrix();
    Mat4 lightProjMatrix = light.getProjMatrix();



    fb.saveAsPPM("output.ppm");

    return 0;
}