// Very basic fragment shader that just uses a single colour
#version 300 es

precision mediump float;
out vec4 fragColor;

void main()
{
    fragColor = vec4(1.0f, 0.2f, 0.2f, 1.0f);
}
