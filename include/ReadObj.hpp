#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "math/Vec3.hpp"
#include <array>



class ReadObj {
    private:
        std::vector<Vec3> vertices;
        std::vector<std::array<int, 3>> faces;


    public:
        ReadObj() {};

        const std::vector<Vec3>& getVertices() const {
            return vertices;
        }

        const std::vector<std::array<int, 3>>& getFaces() const {
            return faces;
        }

        bool load(const std::string& filename) {
            std::ifstream file(filename);
            if (!file.is_open()) {
                return false;
            }

            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string prefix;
                iss >> prefix;

                if (prefix == "v") {
                    float x, y, z;
                    iss >> x >> y >> z;
                    vertices.push_back(Vec3(x, y, z));
                } else if (prefix == "f") {
                    std::vector<int> indices;
                    std::string token;

                    while (iss >> token) {
                        std::istringstream faceStream(token);
                        int idx;
                        char slash;
                        faceStream >> idx; // Read vertex index
                        indices.push_back(idx - 1); // OBJ indices are 1-based so we have to go 0-based
                        // if needed, we can also read texture and normal indices here
                    }

                    for (size_t i = 1; i + 1 < indices.size(); ++i) {
                        faces.push_back({indices[0], indices[i], indices[i + 1]});
                    }
                }
            }

            file.close();
            return true;
        }
    
    
};