#ifndef TEXTURE_H
#define TEXTURE_H

class Texture
{
   private:
    unsigned int _texture;

   public:
    Texture(const char *texture_path);
    ~Texture();

    void use();
};

#endif  // TEXTURE_H