#ifndef ShaderLoader_hpp
#define ShaderLoader_hpp

#include <iostream>
#include <string>
#include <fstream>

class ShaderLoader {
public:
    ShaderLoader();
    ~ShaderLoader();
    std::string load(const char *path) const;
};

#endif /* ShaderLoader_hpp */
