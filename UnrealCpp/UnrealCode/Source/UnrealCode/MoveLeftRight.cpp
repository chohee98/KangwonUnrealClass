// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftRight.h"

// Sets default values
AMoveLeftRight::AMoveLeftRight() : IsMoveRight(true), LocX(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// CreateDefaultSubobject : new 키워드와 같이 언리얼에서 동적으로 객체를 생성하는 키워드
	// TEXT :언리얼에서 사용하는 문자형 중에 하나
	// <USceneComponent>(TEXT("SceneRootRoot") // USceneComponent 객체를 "SceneRootRoot" 이름으로 동적으로 생성
	// <UStaticMeshComponent>(TEXT("mymyMesh") // UStaticMeshComponent 객체를 "mymyMesh" 이름으로 동적으로 생성
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh"));

	SetRootComponent(Scene);	// Scene을 Root Component로 올리겠다.
	//RootComponent = Scene;	// Scene을 Root Component로 올리겠다. (위에와 동일한 기능)

	// AttachToComponent : Component 붙이는 기능
	// Scene에 붙인다. 현재 자표값을 Scene 기준에 Relative(상대) 좌표계로
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
	
}

// Called every frame
void AMoveLeftRight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); // 오버라이드한 함수인 경우 부모 함수를 실행한다.

	if (IsMoveRight)
	{
		LocX += 1; //오른쪽
		if (LocX >= 200)
			IsMoveRight = false; // 움직일 방향
	}
	else
	{
		LocX -= 1; // 왼쪽
		if (LocX <= -200)
			IsMoveRight = true;
	}
	
	
	// SetRelativeLocation : 상대적인 위치값을 설정한다.
	// FVector : 언리얼에서 사용하는 3차원 좌표 변수
	StaticMesh->SetRelativeLocation(FVector(LocX, 0, 0));

}

