#version 410 core

out vec3 color;

uniform sampler2D tex;

in float lightMod;
in vec2 uv;

void	main()
{
	color = texture(tex, uv).rgb * lightMod;
}
