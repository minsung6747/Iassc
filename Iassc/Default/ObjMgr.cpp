#include "stdafx.h"
#include "ObjMgr.h"
#include "CollisionMgr.h"

CObjMgr* CObjMgr::m_pInstance = nullptr;

CObjMgr::CObjMgr()
{
}


CObjMgr::~CObjMgr()
{
	Release();
}

bool CObjMgr::IsPlayer()
{
	if (!m_ObjList[OBJ_PLAYER].empty())
	{
		return true;
	}
	return false;

}
CObj* CObjMgr::Get_Target(OBJID eID, CObj* pObj)
{
	if (m_ObjList[eID].empty())
		return nullptr;

	CObj* pTarget = nullptr;
	float		fDistance = 0.f;

	for (auto& iter : m_ObjList[eID])
	{
		if (iter->Get_Dead())
			continue;

		float	fWidth = abs(pObj->Get_Info().fX - iter->Get_Info().fX);
		float	fHeight = abs(pObj->Get_Info().fY - iter->Get_Info().fY);

		float	fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

		if ((!pTarget) || (fDistance > fDiagonal))
		{
			pTarget = iter;
			fDistance = fDiagonal;
		}
	}

	return pTarget;
}

void CObjMgr::Add_Object(OBJID eID, CObj* pObj)
{
	if ((eID >= OBJ_END) || (nullptr == pObj))
		return;

	m_ObjList[eID].push_back(pObj);
}

int CObjMgr::Update(void)
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end(); )
		{
			int iResult = (*iter)->Update();

			if (OBJ_DEAD == iResult)
			{
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else
				++iter;
		}
	}

	return 0;
}

void CObjMgr::Late_Update(void)
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
		{
			
			iter->Late_Update();
			if (m_ObjList[i].empty())
			{
				break;
			}
		}
	}

	//고정되어 있는 물체  // 움직이는 물체		
	//	void CCollisionMgr::Collision_RectEx(list<CObj*> _Dest, list<CObj*> _Sour)
	CCollisionMgr::Collision_RectEx(m_ObjList[OBJ_BLOCK], m_ObjList[OBJ_PLAYER]);
	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_BLOCK], m_ObjList[OBJ_MBULLET]);

	CCollisionMgr::Collision_RectEx(m_ObjList[OBJ_FLY], m_ObjList[OBJ_PLAYER]);
	CCollisionMgr::Collision_RectEx(m_ObjList[OBJ_HOPPER], m_ObjList[OBJ_PLAYER]);
	CCollisionMgr::Collision_RectEx(m_ObjList[OBJ_ENVY], m_ObjList[OBJ_PLAYER]);
\


	
	
	CCollisionMgr::Collision_RectEx(m_ObjList[OBJ_DOOR], m_ObjList[OBJ_PLAYER],true);
	CCollisionMgr::Collision_RectEx(m_ObjList[OBJ_OBSTACLE], m_ObjList[OBJ_PLAYER]);

	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_OBSTACLE], m_ObjList[OBJ_BULLET]);
	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_BLOCK], m_ObjList[OBJ_BULLET]);
	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_FLY]);
	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_HOPPER]);
	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_ENVY]);



	//CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_MONSTER], m_ObjList[OBJ_BULLET]);
}

void CObjMgr::Render(HDC hDC)
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
			iter->Render(hDC);
	}
}

void CObjMgr::Release(void)
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
			Safe_Delete<CObj*>(iter);

		m_ObjList[i].clear();
	}
}

void CObjMgr::Delete_ID(OBJID eID)
{
	for (auto& iter : m_ObjList[eID])
		Safe_Delete(iter);

	m_ObjList[eID].clear();

}
