#version 330

layout (location = 0) in vec2 point;

out vec2 out_point;
out vec3 color;

void main()
{
    out_point = point;
    color = vec3(1.0, 0.0, 0.0);
}
