#version 330 core
layout (location = 0) in vec3 positions;
//layout (location = 1) in vec3 colors;

out vec3 Colors;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 color;

void main()
{
    //gl_Position =  model *  vec4(positions, 1.0);
    gl_Position = projection * view * model * vec4(positions, 1.0f);
    Colors=color;
}
