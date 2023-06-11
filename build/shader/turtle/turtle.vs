#version 330 core
layout (location = 0) in vec3 positions;
layout (location = 1) in vec2 aTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 TexCoord;

void main()
{
    //gl_Position =  model *  vec4(positions, 1.0);
    gl_Position = projection * view  * model * vec4(positions, 1.0f);
	TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}
