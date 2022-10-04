
#pragma once

#include "GameObject/GameObject.h"
#include "Component/SpriteComponent.h"
#include "Component/ColliderBox2D.h"
#include "Component/CameraComponent.h"


#include "../FSM.h"
#include "../Widget/HP.h"



enum class DASHDIR
{
    LEFT,
    RIGHT,
};

enum class HANGINGDIR
{
    LEFT,
    RIGHT,
};


class Cdummy :
    public CGameObject
{
    friend class CFloor;
    friend class CScene;
    friend class CdummyAnimation;
    friend class Cdummymonster;
    friend class CLMonster;
    friend class CFMonster;
    friend class CBMonster;
    friend class CBMonAttack;
    friend class CFK;
    friend class CFKHeadLeft;
    friend class CFKHeadRight;
    friend class CRockDown;
    friend class CCol;
    friend class CScene0Col;
    friend class CScene1Col;
    friend class CScene2Col;
    friend class CScene3Col;
    friend class CFKAttack;
protected:
    Cdummy();
    Cdummy(const Cdummy& obj);
    virtual ~Cdummy();

private:
    FSM<Cdummy> PlayerFSM;
    CSharedPtr<CHP> HPWidget;
    CSharedPtr<CSpriteComponent>    m_Sprite;   
    CSharedPtr<CColliderBox2D>       m_Body;
    CSharedPtr<CColliderBox2D>       m_IBody;
    CSharedPtr<CColliderBox2D>       m_FBody;

    CSharedPtr<CCameraComponent>     m_Camera;
  
    CSharedPtr<CSceneComponent>     m_Muzzle;
  
    Vector2 CurMapSize;

    CSharedPtr<CSpriteComponent>    DashleftEffect;
    CSharedPtr<CSpriteComponent>    DashrightEffect;

    CSharedPtr<CSpriteComponent>    WingLeft;
    CSharedPtr<CSpriteComponent>    WingRight;

    CSharedPtr<CSpriteComponent>    SkillLeftEffect;
    CSharedPtr<CSpriteComponent>    SkillRightEffect;

    CSharedPtr<CSpriteComponent>    GetAttackEffect;
    int WallTouchedCount;
    int MonColCount;

 

    bool DebugOn;

    bool IsOnAttack;

    bool IsDoubleJumped;
    bool IsOnJump;

    bool IsDirChanged;
  
    bool IsDashed;
    bool IsOnDash;

    bool IsHitFromLeft;

    bool IsTouchedLeftWall;
    bool IsTouchedRightWall;
    bool IsTouchedTopWall;

    bool IsHanging;

    bool IsOnWallJump;

    bool IsInvincible;

    bool IsBeingAttack;

    bool IsOnEvent;
 

    bool IsGetAttackPossible;
    float       GetAttackRate;


    bool IsCanAttack;
    float AttackRate;

    float HaningTime;
    float PRunTime;

    float TextOpacity;

    PHASE Phase;

    CurMap Map;
    DASHDIR DashDir;
    DIR Dir;
    DIR PreDir;
    HANGINGDIR HangDir;


    CSharedPtr<class CSound> DamageSound;
    CSharedPtr<class CSound> DashSound;
    CSharedPtr<class CSound> FallingSound;
    CSharedPtr<class CSound> SkillSound;
    CSharedPtr<class CSound> JumpSound;
    CSharedPtr<class CSound> LandSound;
    CSharedPtr<class CSound> HangSound;
    CSharedPtr<class CSound> ParrySound;
    //CSharedPtr<class CSound> RunSound;
    CSharedPtr<class CSound> WallJumpSound;
    CSharedPtr<class CSound> WallSlideSound;
    CSharedPtr<class CSound> DoubleJumpSound;
    CSharedPtr<class CSound> AttackSound[5];
   
    int PlayerHP;

 



public:
    virtual bool Init();
    virtual void Start();
    virtual void Update(float DeltaTime);
    virtual void PostUpdate(float DeltaTime);
    virtual Cdummy* Clone();
    
    class CAnimationSequence2DInstance* GetAnimationInstance()  const;

    bool GetOnDash()
    {
        return IsOnDash;
    }

    //�浹ü ��ȯ
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
    //�浹ü ��ȯ


    PHASE GetPhase()
    {
        return Phase;
    }

    void SetPhase(PHASE phase)
    {
        Phase = phase;
    }

    //�޴޸��� ���� ����
    HANGINGDIR GetHangDir()
    {
        return HangDir;
    }

    void SetHangDir(HANGINGDIR dir)
    {
        HangDir = dir;
    }
    //�޴޸��� ���� ����

    //�� ���� ���� ����
    bool GetIsHitFromLeft()
    {
        return IsHitFromLeft;
    }

    void SetIsHitFromLeft(bool dir)
    {
        IsHitFromLeft = dir;
    }
    //�� ���� ���� ����

    //�� ��ġ ����
    bool GetIsTouchedLeftWall()
    {
        return IsTouchedLeftWall;
    }

    void SetIsTouchedLeftWall(bool is)
    {
        IsTouchedLeftWall = is;
    }

    bool GetIsTouchedRightWall()
    {
        return IsTouchedRightWall;
    }

    void SetIsTouchedRightWall(bool is)
    {
        IsTouchedRightWall = is;
    }

    bool GetIsTouchedTopWall()
    {
        return IsTouchedTopWall;
    }

    void SetIsTouchedTopWall(bool is)
    {
        IsTouchedTopWall = is;
    }
    //�� ��ġ ����

    //���� ���ΰ� �ƴѰ�
    bool GetIsJumpl()
    {
        return IsOnJump;
    }

    void SetIsJump(bool is)
    {
        IsOnJump = is;
    }
    //���� ���ΰ� �ƴѰ�

    //�� ����
    bool GetIsOnWallJumpl()
    {
        return IsOnWallJump;
    }

    void SetIsOnWallJump(bool is)
    {
        IsOnWallJump = is;
    }
    //�� ����



    //�� ���� Ƚ��
    void AddWallTouchedCount()
    {
        WallTouchedCount++;
    }

    void SubWallTouchedCount()
    {
        WallTouchedCount--;
    }

    int GetWallTouchedCount()
    {
        return WallTouchedCount;
    }
    //�� ���� Ƚ��
    
    //����
    bool GetIsInvincible()
    {
        return IsInvincible;
    }

    void SetIsInvincible(bool is)
    {
        IsInvincible = is;
    }

    //�ǰݰ���
    bool GetIsGetAttackPossible()
    {
        return IsGetAttackPossible;
    }

    void SetIsGetAttackPossible(bool is)
    {
        IsGetAttackPossible = is;
    }

    //���� �ǰ� Ƚ��
    void AddMonColCount()
    {
        MonColCount++;
    }

    void SubMonColCount()
    {
        MonColCount--;
    }

    int GetMonColCount()
    {
        return MonColCount;
    }

    Vector2 GetCurMapSize()
    {
        return CurMapSize;
    }

    void SetCurMapSize(Vector2 size);
  
    void SetCurMap(CurMap a)
    {
        Map = a;
    }

    //�ǰ����ΰ�
    bool GetIsBeingAttack()
    {
        return IsBeingAttack;
    }


    //�̺�Ʈ
    void SetIsOnEvent(bool _b)
    {
        IsOnEvent = _b;
    }

    void CheckCamera();
    void ChangeAnimation(const std::string& AniName);

    void KeyCheck();
    void ChangeState(const std::string& Name);
private:
 



    void IDLEStart();
    void IDLEStay();
    
    
    
    void MOVEStartStart();
    void MOVEStartStay();


    void MOVEStopStart();
    void MOVEStopStay();
 

    void TURNStart();
    void TURNStay();
 

    void MOVEStart();
    void MOVEStay();
    void MOVEEnd();
    
    void JUMPStart();
    void JUMPStay();
    void JUMPEnd();

    void JUMPDownStart();
    void JUMPDownStay();

    void DOUBLEJUMPStart();
    void DOUBLEJUMPStay();
    void DOUBLEJUMPEnd();

    void HANGINGStart();
    void HANGINGStay();
    void HANGINGEnd();

    void JUMPFROMWALLStart();
    void JUMPFROMWALLStay();
    void JUMPFROMWALLEnd();

    void LANDStart();
    void LANDStay();

    void DASHStart();
    void DASHStay();
    void DASHEnd();

    void GETATTACKStart();
    void GETATTACKStay();
    void GETATTACKEnd();
 

    void RESTOREStart();
    void RESTOREStay();

    void ATTACKStart();
    void ATTACKStay();
    void ATTACKEnd();

    void ATTACKUPStart();
    void ATTACKUPStay();
    void ATTACKUPEnd();

    void ATTACKDOWNStart();
    void ATTACKDOWNStay();
    void ATTACKDOWNEnd();

    void AFTERDOWNATTACKStart();
    void AFTERDOWNATTACKStay();

    void SKILLStart();
    void SKILLStay();
    void SKILLEnd();

    


private:
    float MoveStartTime;
    float MoveStopTime;
    float TurnTime;
    float JumpTime;
    float LandTime;
    float AttackTime;
    float DashTime;
    float JumpHeight;
    float JumpCurrentHeight;
    float DoubleJumpTime;

    float AfterDownAttackTime;

    float RestoreTime;
    float GetAttackTime;

    float DoubleJumpHeight;
    float DoubleJumpCurrentHeight;

private:
    void OnCollisionBegin(const CollisionResult& result);
    void OnCollisionEnd(const CollisionResult& result);

    void IOnCollisionBegin(const CollisionResult& result);
    void IOnCollisionEnd(const CollisionResult& result);
};

