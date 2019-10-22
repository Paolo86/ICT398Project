#include "pch.h"
#include "Mountain.h"
#include "..\Utils\ContentManager.h"
#include "..\Components\BoxCollider.h"

Mountain::Mountain() : GameObject("Mountain")
{
	SetIsStatic(true);
	ContentManager::Instance().GetAsset<Model>("Mountain")->PopulateGameObject(this);
	//transform.SetScale(1.5);
	SetCullable(false);
	Material m;
	m.SetShader(ContentManager::Instance().GetAsset<Shader>("DefaultStatic"));
	m.Loadtexture(ContentManager::Instance().GetAsset<Texture2D>("Mountain"));
	m.LoadFloat("shininess", 400.0f);
	m.SetColor(0.5, 0.5, 0.5);
	//m.Loadtexture(ContentManager::Instance().GetAsset<Texture2D>("BushCourt"), "diffuse0");
//	m.LoadFloat("shininess", 300.0f);
	ApplyMaterial(m);

	Material m2NoLight;
	m2NoLight.SetShader(ContentManager::Instance().GetAsset<Shader>("DefaultStaticNoLight"));
	m2NoLight.Loadtexture(ContentManager::Instance().GetAsset<Texture2D>("Mountain"), "diffuse0");
	ApplyMaterial(m2NoLight, NOLIGHT);

}

Mountain::~Mountain()
{

}

void Mountain::Update()
{
	GameObject::Update();
}

void Mountain::Start()
{
	GameObject::Start(); //This will call start on all the object components, so it's better to leave it as last call when the collider
						 // has been added.
}