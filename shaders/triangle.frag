#version 410 core
// Fragment shader: runs once per pixel the triangle covers.
in vec3 vColor;
out vec4 FragColor;

void main()
{
    FragColor = vec4(vColor, 1.0);
}
