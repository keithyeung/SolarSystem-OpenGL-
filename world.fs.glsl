#version 330

uniform sampler2D u_diffuse;

in  vec2 f_texcoord;
out vec4 frag_color;

void main() {
   frag_color = texture(u_diffuse, f_texcoord);
}