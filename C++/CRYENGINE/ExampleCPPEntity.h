// Matthew Robinson

#pragma once

#include "IGameObject.h"

struct CExampleCPPEntity : public CGameObjectExtensionHelper < CExampleCPPEntity, IGameObjectExtension >
{
	CExampleCPPEntity(){}

	virtual ~CExampleCPPEntity(){}

	virtual bool Init(IGameObject *pGameObject);
	virtual void InitClient(int channelId) {};
	virtual void PostInit(IGameObject *pGameObject);
	virtual void PostInitClient(int channelId) {};
	virtual bool ReloadExtension(IGameObject * pGameObject, const SEntitySpawnParams &params) { return true; };
	virtual void PostReloadExtension(IGameObject * pGameObject, const SEntitySpawnParams &params) {}
	virtual bool GetEntityPoolSignature(TSerialize signature) { return true; };
	virtual void Release() {};
	virtual void FullSerialize(TSerialize ser) {};
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8 profile, int flags) { return true; };
	virtual void PostSerialize() {}
	virtual void SerializeSpawnInfo(TSerialize ser) {}
	virtual ISerializableInfoPtr GetSpawnInfo() { return 0; }
	virtual void Update(SEntityUpdateContext &ctx, int updateSlot);
	virtual void PostUpdate(float frameTime) {};
	virtual void PostRemoteSpawn() {};
	virtual void HandleEvent(const SGameObjectEvent &) {};
	virtual void ProcessEvent(SEntityEvent &) {};
	virtual void SetChannelId(uint16 id) {}
	virtual void SetAuthority(bool auth) {};
	virtual void GetMemoryUsage(ICrySizer *pSizer) const {};

};