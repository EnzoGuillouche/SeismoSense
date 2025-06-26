#include "character.hpp"

Text::Text(std::string text, std::vector<float> pos, unsigned int textVAO, unsigned int textVBO)
{
    this->text = text;
    this->pos = pos;
    this->textVAO = textVAO;
    this->textVBO = textVBO;
    this->loadFont("Fonts/Roboto/Roboto-VariableFont.ttf");
}

void Text::setPos(std::vector<float> newPos)
{
    this->pos = newPos;
}

void Text::loadFont(const char* fontPath) 
{
    FT_Library ft;

    if (FT_Init_FreeType(&ft))
        std::cerr << "ERROR::FREETYPE: Could not init FreeType\n";

    FT_Face face;
    if (FT_New_Face(ft, fontPath, 0, &face))
        std::cerr << "ERROR::FREETYPE: Failed to load font\n";

    FT_Set_Pixel_Sizes(face, 0, 48); // height in pixels

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // disable byte-alignment restriction

    for (unsigned char c = 0; c < 128; c++) {
        if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
            std::cerr << "ERROR::FREETYTPE: Failed to load Glyph\n";
            continue;
        }

        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
            GL_TEXTURE_2D, 0, GL_RED,
            face->glyph->bitmap.width, face->glyph->bitmap.rows,
            0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer
        );

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        this->characters[c] = {
            texture,
            glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
            glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
            static_cast<unsigned int>(face->glyph->advance.x)
        };
    }

    FT_Done_Face(face);
    FT_Done_FreeType(ft);

    // Set up VAO/VBO
    glGenVertexArrays(1, &this->textVAO);
    glGenBuffers(1, &this->textVBO);
    glBindVertexArray(this->textVAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->textVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, nullptr, GL_DYNAMIC_DRAW); // 6 vertices, 4 floats each (x, y, u, v)
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
