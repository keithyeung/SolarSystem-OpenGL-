#pragma once
#include "graphics.hpp"
#include "mesh.hpp"
#include "system.hpp"
#include <vector>

class planet_data
{
public:
	texture_t                        m_texture;
	glm::vec3                        m_position{};
	float                            m_rotation{};
	glm::mat4                        m_transform{};
	void PlanetUpdate(const timespan_t& deltatime,const float p_speed,const glm::vec3 distance_from_origin);
};


class Scene : planet_data
{
public:
	Scene();
	~Scene();

	void on_update(const timespan_t &deltatime,
				   const timespan_t &apptime);
	void on_render(shared_t m_shared, renderer_t m_renderer);

	bool create_cube_assets();

	mesh_t                           m_mesh;

	planet_data sun;
	planet_data mercury;
	planet_data venus;
	planet_data earth;
	planet_data mars;
	planet_data jupiter;
	planet_data saturn;
	planet_data uranus;
	planet_data neptune;

	planet_data moon;

	std::vector<planet_data*>		 planet_vec;
	
private:
	float							 m_speed;
	glm::vec3						 m_distance_from_origin{};
private:
	float UpdateSpeed();
	glm::vec3 Update_Distance();
	void ResetSpeedAndDis();
	//void Initializer(planet_data p_planet);
};

