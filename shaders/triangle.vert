#version 410 core
// Vertex shader: runs once per vertex. Rotates the triangle by uAngle.
layout(location = 0) in vec2 aPos;
layout(location = 1) in vec3 aColor;

uniform float uAngle;

out vec3 vColor;

void main()
{
    float c = cos(uAngle);
    float s = sin(uAngle);
    vec2 p = vec2(c * aPos.x - s * aPos.y,
                  s * aPos.x + c * aPos.y);
    gl_Position = vec4(p, 0.0, 1.0);
    vColor = aColor;
}
