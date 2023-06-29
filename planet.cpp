#include "planet.hpp"
#include <glm/gtc/matrix_transform.hpp>


Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::on_render(shared_t p_shared, renderer_t p_renderer)
{
	
}

void Scene::on_update(const timespan_t &deltatime,
					   const timespan_t &apptime)
{					
	ResetSpeedAndDis();
	//sun
	sun.m_rotation += deltatime.elapsed_seconds();
	sun.m_transform = glm::translate(glm::mat4(1.0f), sun.m_position) *
		glm::rotate(glm::mat4(1.0f), sun.m_rotation, glm::normalize(glm::vec3(0.0f, -2.0f, 0.0f)));

	//Planets
	Update_Distance();
	mercury.PlanetUpdate(deltatime, m_speed, m_distance_from_origin);

	UpdateSpeed();
	Update_Distance();
	venus.PlanetUpdate(deltatime, m_speed, m_distance_from_origin);

	UpdateSpeed();
	Update_Distance();
	earth.PlanetUpdate(deltatime, m_speed, m_distance_from_origin);

	UpdateSpeed();
	Update_Distance();
	mars.PlanetUpdate(deltatime, m_speed, m_distance_from_origin);

	UpdateSpeed();
	Update_Distance();
	jupiter.PlanetUpdate(deltatime, m_speed, m_distance_from_origin);

	UpdateSpeed();
	Update_Distance();
	saturn.PlanetUpdate(deltatime, m_speed, m_distance_from_origin);

	UpdateSpeed();
	Update_Distance();
	uranus.PlanetUpdate(deltatime, m_speed, m_distance_from_origin);

	UpdateSpeed();
	Update_Distance();
	neptune.PlanetUpdate(deltatime, m_speed, m_distance_from_origin);


	//Moon
	const float moon_speed = 2.0f;
	moon.m_rotation += deltatime.elapsed_seconds() * moon_speed;
	moon.m_transform = glm::translate(earth.m_transform, {0,0,0}) *
		glm::rotate(glm::mat4(1.0f), moon.m_rotation, glm::normalize(glm::vec3(0.0f, -2.0f, 0.0f))) *
		glm::translate(glm::mat4(1.0f), {2.0f,0.0f,0.0f});
		
}


bool Scene::create_cube_assets()
{
	if (!sun.m_texture.create_from_file("assets/sun.jpg", true)) {
		return false;
	}
	if (!mercury.m_texture.create_from_file("assets/mercury.jpg", true)) {
		return false;
	}
	if (!venus.m_texture.create_from_file("assets/venus.jpg", true)) {
		return false;
	}
	if (!earth.m_texture.create_from_file("assets/earth.jpg", true)) {
		return false;
	}
	if (!mars.m_texture.create_from_file("assets/mars.jpg", true)) {
		return false;
	}
	if (!jupiter.m_texture.create_from_file("assets/jupiter.jpg", true)) {
		return false;
	}
	if (!saturn.m_texture.create_from_file("assets/saturn.jpg", true)) {
		return false;
	}
	if (!uranus.m_texture.create_from_file("assets/uranus.jpg", true)) {
		return false;
	}
	if (!neptune.m_texture.create_from_file("assets/neptune.jpg", true)) {
		return false;
	}
	if (!moon.m_texture.create_from_file("assets/moon.jpg", true)) {
		return false;
	}

	if (!mesh_t::make_cube_indexed(m_mesh)) {
		return false;
	}
	
	const glm::vec3 preset_position = { 0.0f,0.0f,-40.0f };
	sun.m_position = preset_position;
	sun.m_transform = glm::translate(glm::mat4(1.0f), sun.m_position);

	mercury.m_position = preset_position;
	mercury.m_transform = glm::translate(glm::mat4(1.0f), mercury.m_position);

	venus.m_position = preset_position;
	venus.m_transform = glm::translate(glm::mat4(1.0f), venus.m_position);

	earth.m_position = preset_position;
	earth.m_transform = glm::translate(glm::mat4(1.0f), earth.m_position);

	mars.m_position = preset_position;
	mars.m_transform = glm::translate(glm::mat4(1.0f), mars.m_position);

	jupiter.m_position = preset_position;
	jupiter.m_transform = glm::translate(glm::mat4(1.0f), jupiter.m_position);

	saturn.m_position = preset_position;
	saturn.m_transform = glm::translate(glm::mat4(1.0f), saturn.m_position);

	uranus.m_position = preset_position;
	uranus.m_transform = glm::translate(glm::mat4(1.0f), uranus.m_position);

	neptune.m_position = preset_position;
	neptune.m_transform = glm::translate(glm::mat4(1.0f), neptune.m_position);

	moon.m_position = preset_position;
	moon.m_transform = glm::translate(glm::mat4(1.0f), moon.m_position);

	return true;
}

float Scene::UpdateSpeed()
{
	return m_speed -= 0.2f;
}

glm::vec3 Scene::Update_Distance()
{
	const glm::vec3 distance{ 4,0,0 };
	return m_distance_from_origin += distance;
}

void Scene::ResetSpeedAndDis()
{
	m_speed = 1.8f;
	m_distance_from_origin = { 0,0,0 };
}

void planet_data::PlanetUpdate(const timespan_t& deltatime,const float p_speed,const glm::vec3 distance_from_origin)
{
	m_rotation += deltatime.elapsed_seconds() * p_speed;
	m_transform = glm::translate(glm::mat4(1.0f), m_position) *
		glm::rotate(glm::mat4(1.0f), m_rotation, glm::normalize(glm::vec3(0.0f, -2.0f, 0.0f))) *
		glm::translate(glm::mat4(1.0f), distance_from_origin) *
		glm::rotate(glm::mat4(1.0f), m_rotation, glm::normalize(glm::vec3(0.0f,-2.0f,0.0f)));
}


