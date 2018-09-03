#version 410 core

layout(location = 0) in vec3 point;

uniform mat4 projection;
uniform mat4 transform;

out float lightMod;
out vec2 uv;

void	main()
{
	float angle1 = acos(dot(normalize(point), vec3(1, 0, 0)));
	float angle2 = acos(dot(normalize(point), vec3(0, 1, 0)));

	uv = -vec2(angle1, angle2) / 3.14159;

	vec4 vertexPos = transform * vec4(point, 1) + vec4(0, 0, -3, 0);
	vec4 norm = transform * vec4(-point, 0);
	gl_Position = projection * vertexPos;
	lightMod = max(abs(dot(norm, vec4(0, 0, 1, 0))), 0.2);
}

