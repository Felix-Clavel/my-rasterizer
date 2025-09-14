#include <vector>
#include <string>
#include "math/Vec3.hpp"

class FrameBuffer
{
    private:
        int width;
        int height;

        std::vector<u_int32_t> colorBuffer;
        std::vector<float> depthBuffer;

    public:
        FrameBuffer(int w, int h);

        void clear(u_int32_t color, float depth = 1.0f);

        void setPixel(int x, int y, u_int32_t color, float depth);
        u_int32_t getPixel(int x, int y) const;
        float getDepth(int x, int y) const;

        int getWidth() const;
        int getHeight() const;

        void saveAsPPM(const std::string& filename) const;


};
