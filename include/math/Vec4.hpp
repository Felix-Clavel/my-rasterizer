#pragma once

class Vec4 {
    private:
        float x, y, z, w;

    public:

        Vec4() : x(0), y(0), z(0), w(0) {};

        Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {};

        // TODO capter si c'est vraiment utile de mettre en privée avec des getters/setters
        float getX() const { return x; }
        float getY() const { return y; }
        float getZ() const { return z; }
        float getW() const { return w; }

        void setX(float val) { x = val; }
        void setY(float val) { y = val; }
        void setZ(float val) { z = val; }
        void setW(float val) { w = val; }

};