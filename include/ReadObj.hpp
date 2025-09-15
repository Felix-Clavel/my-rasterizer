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
        std::vector<std::array<int, 3>> texIdx;
        std::vector<std::array<int, 3>> normIdx;


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
                    std::vector<int> vIdx, tIdx, nIdx;
                    std::string token;

                    while (iss >> token) {
                        int vi = -1, ti = -1, ni = -1;
                        size_t firstSlash = token.find('/');
                        size_t secondSlash = token.find('/', firstSlash + 1);

                        if (firstSlash == std::string::npos) {
                            vi = std::stoi(token) - 1;
                        } else if (secondSlash == std::string::npos) {
                            // v/t
                            vi = std::stoi(token.substr(0, firstSlash)) - 1;
                            ti = std::stoi(token.substr(firstSlash + 1)) - 1;
                        } else {
                            // v/t/n or v//n
                            vi = std::stoi(token.substr(0, firstSlash)) - 1;
                            if (secondSlash > firstSlash + 1) {
                                ti = std::stoi(token.substr(firstSlash + 1, secondSlash - firstSlash - 1)) - 1;
                            }
                            ni = std::stoi(token.substr(secondSlash + 1)) - 1;
                        }
                        vIdx.push_back(vi);
                        tIdx.push_back(ti);
                        nIdx.push_back(ni);
                    }

                    for (size_t i = 1; i + 1 < vIdx.size(); ++i) {
                        faces.push_back({vIdx[0], vIdx[i], vIdx[i + 1]});
                        texIdx.push_back({tIdx[0], tIdx[i], tIdx[i + 1]});
                        normIdx.push_back({nIdx[0], nIdx[i], nIdx[i + 1]});
                    }
                }

            file.close();
            return true;
            }
        }
    
};