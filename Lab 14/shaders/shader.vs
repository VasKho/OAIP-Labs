#version 330

layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 in_tex_Coord;

uniform vec2 offset;

out vec2 Tex_Coord;

void main()
{
    gl_Position = vec4(pos.x + offset.x, pos.y + offset.y, pos.z, 1.0);
    Tex_Coord = in_tex_Coord;
}