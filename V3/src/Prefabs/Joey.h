#pragma once
#include "..\Core\GameObject.h"

class AffordanceObject;

class Joey : public GameObject
{

public:
	Joey();
	~Joey();

	void Update() override;
	void Start() override;
	void OnCollisionEnter(Collider* g, Collision& collision) override;
	void OnCollisionStay(Collider* g, Collision& collision) override;
	void OnCollisionExit(Collider* g) override;
	void Test(AffordanceObject*);
private:

};