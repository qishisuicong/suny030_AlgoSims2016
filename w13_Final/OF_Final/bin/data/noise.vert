#version 120

uniform float time;

void main() {
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
