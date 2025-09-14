#include <vector>
#include "FrameBuffer.hpp"
#include "Camera.hpp"
#include "math/Mat4.hpp"



int main() {
    FrameBuffer fb(800, 600);
    fb.clear(0x000000);

    // Handle the initialization here
    fb.setPixel(400, 300, 0xFF0000, 0.5f);

    // Handle the initialization of the camera here
    // Camera cam;






    fb.saveAsPPM("output.ppm");

    return 0;
}