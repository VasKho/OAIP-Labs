#version 330

in vec2 Tex_Coord;
uniform sampler2D Texture;

out vec4 FragColor;

void main()
{
    FragColor = texture(Texture, Tex_Coord);
}