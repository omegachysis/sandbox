// Matthew Robinson

#include "StdAfx.h"

#include "ExampleCPPEntity.h"

bool CExampleCPPEntity::Init(IGameObject * pGameObject)
{
	SetGameObject(pGameObject);
	return true;
}

void CExampleCPPEntity::PostInit(IGameObject *pGameObject)
{
	pGameObject->EnableUpdateSlot(this, 0);
}

void CExampleCPPEntity::Update(SEntityUpdateContext &ctx, int updateSlot)
{
	gEnv->pLog->Log("Updates Enabled");
}