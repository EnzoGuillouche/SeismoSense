#pragma once

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <iostream>
#include <map>
#include <vector>

struct Character {
    unsigned int textureID; // glyph texture
    glm::ivec2 size;        // size of glyph
    glm::ivec2 bearing;     // offset from baseline to left/top
    unsigned int advance;   // offset to advance to next glyph
};

class Text
{
private:
    unsigned int textVAO, textVBO;
    std::string text;
    std::vector<float> pos;
    std::map<char, Character> characters;

public:
    Text(std::string text, std::vector<float> pos, unsigned int textVAO, unsigned int textVBO);
    void loadFont(const char* fontPath);
    unsigned int getVAO();
    unsigned int getVBO();
    std::string getText();
    std::vector<float> getPos();
    std::map<char, Character> getCharacters();
};