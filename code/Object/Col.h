#pragma once

#include "GameObject/GameObject.h"
#include "Component/SpriteComponent.h"
#include "Component/PaperBurnComponent.h"
#include "Component/ColliderCircle.h"
#include "Component/WidgetComponent.h"
#include "Component/ColliderBox2D.h"

class CCol :
    public CGameObject
{
    friend class CScene;

protected:
    CCol();
    CCol(const CCol& obj);
    virtual ~CCol();

private:
    CSharedPtr<CSpriteComponent>    m_Sprite;
    CSharedPtr<CColliderBox2D>       m_Body;
    CSharedPtr<CColliderBox2D>       m_MonBody;
   

  

public:
    virtual void Start();
    virtual bool Init();
    virtual void Update(float DeltaTime);
    virtual void PostUpdate(float DeltaTime);
    virtual CCol* Clone();

    Vector2 GetColCenterPos()
    {
        return m_Body->GetInfo().Center;
    }

    float GetColTopYPos()
    {
        return m_Body->GetInfo().Max.y;
    }

    float GetColBottomYPos()
    {
        return m_Body->GetInfo().Min.y;
    }

    float GetColLeftXPos()
    {
        return m_Body->GetInfo().Min.x;
    }

    float GetColRightXPos()
    {
        return m_Body->GetInfo().Max.x;
    }

    void SetColExtent(Vector2 vec)
    {
        m_Body->SetExtent(vec.x, vec.y);
    }


    //���Ϳ� �浹ü
    Vector2 MGetColCenterPos()
    {
        return m_MonBody->GetInfo().Center;
    }

    float MGetColTopYPos()
    {
        return m_MonBody->GetInfo().Max.y;
    }

    float MGetColBottomYPos()
    {
        return m_MonBody->GetInfo().Min.y;
    }

    float MGetColLeftXPos()
    {
        return m_MonBody->GetInfo().Min.x;
    }

    float MGetColRightXPos()
    {
        return m_MonBody->GetInfo().Max.x;
    }

    void MSetColExtent(Vector2 vec)
    {
        m_MonBody->SetExtent(vec.x, vec.y);
    }


public:
    void OnCollisionBegin(const CollisionResult& result);
    void OnCollisionEnd(const CollisionResult& result);

    void MOnCollisionBegin(const CollisionResult& result);
    void MOnCollisionEnd(const CollisionResult& result);

};


