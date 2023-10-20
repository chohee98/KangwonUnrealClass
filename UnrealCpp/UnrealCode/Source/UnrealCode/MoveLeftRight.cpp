// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftRight.h"
#include "Switch.h"

// Sets default values
AMoveLeftRight::AMoveLeftRight() : m_LocX(0), m_IsMoveRight(true), m_IsPlay(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh"));

	SetRootComponent(Scene);

	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

	// RootComponent에 붙인다. 현재 자표값을 RootComponent 기준에 Relative(상대) 좌표계로
	//StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	// UAsset 가져오기
	// ConstructorHelpers::FObjectFinder : 오브젝트 에셋을 찾는다.
	// <UStaticMesh> : 찾을 에셋 타입
	// sm : 찾아서 넣을 객체 이름
	/* (비추)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> sm(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));

	if (sm.Succeeded()) //에셋 불러오기 성공 여부 체크
	{
		StaticMesh->SetStaticMesh(sm.Object); // StaticMeshComponent에 StaticMesh 적용
	}*/
}

AMoveLeftRight::~AMoveLeftRight()
{
}

// Called when the game starts or when spawned
void AMoveLeftRight::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(m_Switch))
		m_Switch->FDele_EventOverlap.AddDynamic(this, &AMoveLeftRight::EventOverlap);	
}

// Called every frame
void AMoveLeftRight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); // 오버라이드한 함수인 경우 부모 함수를 실행한다.

	if (m_IsPlay == false)
		return;

	if (m_IsMoveRight)
	{
		m_LocX += 1; //오른쪽
		if (m_LocX >= 200)
			m_IsMoveRight = false; // 움직일 방향
	}
	else
	{
		m_LocX -= 1; // 왼쪽
		if (m_LocX <= -200)
			m_IsMoveRight = true;
	}
	
	
	// SetRelativeLocation : 상대적인 위치값을 설정한다.
	// FVector : 언리얼에서 사용하는 3차원 좌표 변수
	StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, 0));
}

void AMoveLeftRight::EventOverlap(bool isBegin)
{
	m_IsPlay = isBegin;
}

void AMoveLeftRight::Code_DoPlay_Implementation(bool IsPlay)
{
	m_IsPlay = IsPlay;
}

