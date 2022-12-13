#version 300 es

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoords;

out vec2 otexCoords;

uniform mat4 transform;
uniform mat4 viewProjection;

void main()
{
    gl_Position = viewProjection * transform * vec4(position, 1);
    otexCoords = texCoords;
}

