#include "Background.h"


void Background::Add(const std::filesystem::path& texturePath, int level)
{
    CS230::Texture::Texture(texturePath);

}

void Background::Unload()
{
    backgrounds.clear();
}

void Background::Draw(const CS230::Camera& camera)
{

}


math::ivec2 Background::Size()
{
    ParallaxInfo Parall;
    return static_cast<math::ivec2>(Parall.level);
}