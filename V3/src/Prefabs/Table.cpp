#include "pch.h"
#include "Table.h"
#include "..\Utils\ContentManager.h"
#include "..\Components\BoxCollider.h"

Table::Table() : GameObject("Table")
{
	//SetIsStatic(false);
	ContentManager::Instance().GetAsset<Model>("Table")->PopulateGameObject(this);
	transform.SetScale(0.1);
	Material m;
	m.SetShader(ContentManager::Instance().GetAsset<Shader>("PBR"));
	m.Loadtexture(ContentManager::Instance().GetAsset<Texture2D>("wood_normal"), "normalMap");
	m.Loadtexture(ContentManager::Instance().GetAsset<Texture2D>("wood_albedo"), "albedoMap");
	m.Loadtexture(ContentManager::Instance().GetAsset<Texture2D>("wood_roughness"), "roughnessMap");
	m.Loadtexture(ContentManager::Instance().GetAsset<Texture2D>("wood_ao"), "aoMap");
	m.Loadtexture(ContentManager::Instance().GetAsset<Texture2D>("wood_metallic"), "metallicMap");


	m.LoadCubemap(ContentManager::Instance().GetAsset<CubeMap>("SunSet"), "cubemap0");
	ApplyMaterial(m);

}

Table::~Table()
{

}

void Table::Update()
{
	GameObject::Update();
}

void Table::Start()
{

	LoadCollidersFromFile("Assets\\Colliders\\Table.txt");

	GameObject::Start(); //This will call start on all the object components, so it's better to leave it as last call when the collider
						 // has been added.
}

void Table::OnCollision(GameObject* g)
{
	Logger::LogInfo("Collided against", g->GetName());
}