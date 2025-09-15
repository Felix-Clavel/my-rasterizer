#pragma once

class Vec3 {
    private :
        float x, y, z;
    
    public :
        Vec3() : x(0), y(0), z(0) {};

        Vec3(float x, float y, float z) : x(x), y(y), z(z) {};
        

        float getX() const { return x; }
        float getY() const { return y; }
        float getZ() const { return z; }
        
        void setX(float val) { x = val; }
        void setY(float val) { y = val; }
        void setZ(float val) { z = val; }
};