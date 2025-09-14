#include "FrameBuffer.hpp"
#include <fstream>
#include <algorithm>


FrameBuffer::FrameBuffer(int width, int height) 
    : width(width), height(height),
      colorBuffer(width * height, 0),
      depthBuffer(width * height, 1.0f) {}

void FrameBuffer::clear(u_int32_t color, float depth) {
    std::fill(colorBuffer.begin(), colorBuffer.end(), color);
    std::fill(depthBuffer.begin(), depthBuffer.end(), depth);
}

void FrameBuffer::setPixel(int x, int y, u_int32_t color, float depth) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return; // TODO handle out-of-bounds
    }
    int index = y * width + x;
    if (depth < depthBuffer[index]) {
        colorBuffer[index] = color;
        depthBuffer[index] = depth;
    }
}

u_int32_t FrameBuffer::getPixel(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return 0; // TODO handle out-of-bounds
    }
    return colorBuffer[y * width + x];
}

float FrameBuffer::getDepth(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return 1.0f; // TODO handle out-of-bounds
    }
    return depthBuffer[y * width + x];
}

int FrameBuffer::getWidth() const {
    return width;
}

int FrameBuffer::getHeight() const {
    return height;
}


void FrameBuffer::saveAsPPM(const std::string& filename) const {
    std::ofstream ofs(filename, std::ios::binary);
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (auto color : colorBuffer) {
        unsigned char r = (color >> 16) & 0xFF;
        unsigned char g = (color >> 8) & 0xFF;
        unsigned char b = color & 0xFF;
        ofs << r << g << b;
    }
}
// TODO handle the closing of the file and errors

