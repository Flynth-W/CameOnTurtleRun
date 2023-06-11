#pragma once

#include "../shader.hpp"
#include "stb/stb_image.h"
#include "stb/stb_image_resize.h"
#include "stb/stb_image_write.h"

class Textures{
    public:
        static unsigned int loadTexture(char const * path);
        static unsigned int loadTexture(char const * path, bool gammaCorrection);
};
