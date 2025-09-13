#include <vector>
#include <string>
#include "math/Vecteur.hpp"

class FrameBuffer
{
private:
    int width;
    int height;

    std::vector<Vecteur> vertexes;

public:
    FrameBuffer(int w, int h) : width(w), height(h) {};
    void readFile(const std::string &filename);

    void writePPM(const std::string &filename);
};
