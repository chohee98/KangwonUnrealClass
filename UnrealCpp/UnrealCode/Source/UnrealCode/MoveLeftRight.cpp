// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftRight.h"

// Sets default values
AMoveLeftRight::AMoveLeftRight() : IsMoveRight(true), LocX(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// CreateDefaultSubobject : new Ű����� ���� �𸮾󿡼� �������� ��ü�� �����ϴ� Ű����
	// TEXT :�𸮾󿡼� ����ϴ� ������ �߿� �ϳ�
	// <USceneComponent>(TEXT("SceneRootRoot") // USceneComponent ��ü�� "SceneRootRoot" �̸����� �������� ����
	// <UStaticMeshComponent>(TEXT("mymyMesh") // UStaticMeshComponent ��ü�� "mymyMesh" �̸����� �������� ����
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh"));

	SetRootComponent(Scene);	// Scene�� Root Component�� �ø��ڴ�.
	//RootComponent = Scene;	// Scene�� Root Component�� �ø��ڴ�. (������ ������ ���)

	// AttachToComponent : Component ���̴� ���
	// Scene�� ���δ�. ���� ��ǥ���� Scene ���ؿ� Relative(���) ��ǥ���
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

	// RootComponent�� ���δ�. ���� ��ǥ���� RootComponent ���ؿ� Relative(���) ��ǥ���
	//StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	// UAsset ��������
	// ConstructorHelpers::FObjectFinder : ������Ʈ ������ ã�´�.
	// <UStaticMesh> : ã�� ���� Ÿ��
	// sm : ã�Ƽ� ���� ��ü �̸�
	/* (����)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> sm(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));

	if (sm.Succeeded()) //���� �ҷ����� ���� ���� üũ
	{
		StaticMesh->SetStaticMesh(sm.Object); // StaticMeshComponent�� StaticMesh ����
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
	Super::Tick(DeltaTime); // �������̵��� �Լ��� ��� �θ� �Լ��� �����Ѵ�.

	if (IsMoveRight)
	{
		LocX += 1; //������
		if (LocX >= 200)
			IsMoveRight = false; // ������ ����
	}
	else
	{
		LocX -= 1; // ����
		if (LocX <= -200)
			IsMoveRight = true;
	}
	
	
	// SetRelativeLocation : ������� ��ġ���� �����Ѵ�.
	// FVector : �𸮾󿡼� ����ϴ� 3���� ��ǥ ����
	StaticMesh->SetRelativeLocation(FVector(LocX, 0, 0));

}

