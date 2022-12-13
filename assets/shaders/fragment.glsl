#version 300 es

precision mediump float;

in vec2 otexCoords;

uniform vec4 color;
uniform sampler2D tex;

out vec4 ocolor;

void main()
{
    ocolor = texture(tex, otexCoords);
}
