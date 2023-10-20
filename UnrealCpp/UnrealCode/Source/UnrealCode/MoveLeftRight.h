// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"	// ������ �ӵ��� ������ �ϱ����� �⺻���� �ּ��ѿ� ���̺귯�� ������ ���
#include "Public/Tools/InterfacePlayObj.h"
#include "GameFramework/Actor.h"	// AActor Ŭ���� ��� ����

// generated.h �𸮾� Ŭ���� ���� ó���ϴ� ��� (�߿�!!) - �𸮾� Ŭ���� ���� �⺻ ��Ģ
// ��� �𸮾� Ŭ������ �����Ƿ��� �Ʒ� �ڵ带 �־���� �Ѵ�.
//  �ݵ�� ��� #include �������� ��ġ
#include "MoveLeftRight.generated.h"	

// UNREALCODE_API : �� Ŭ������ UNREALCODE_API ��⿡ ���Եȴ�.
UCLASS()	//�𸮾� Ŭ���� ���� - �𸮾� Ŭ���� ���� �⺻ ��Ģ
class UNREALCODE_API AMoveLeftRight : public AActor, public IInterfacePlayObj // public AActor : AActor�� ��� ��� �ްڴ�.
{
	GENERATED_BODY() //�𸮾� �ڵ� ���� �Լ� - �𸮾� Ŭ���� ���� �⺻ ��Ģ

public:	
	// Sets default values for this actor's properties
	AMoveLeftRight();
	~AMoveLeftRight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void EventOverlap(bool isBegin);

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Code_DoPlay(bool IsPlay);// �������Ʈ ȣ��� �Լ��� ����

	virtual void Code_DoPlay_Implementation(bool IsPlay) override;// c++���� ����� �Լ�

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	// UPROPERTY : https://docs.unrealengine.com/4.26/ko/ProgrammingAndScripting/GameplayArchitecture/Properties/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh; 
	// �����ʹ� ����Ű�� ��. ��ü�� �ƴ�. new�� ����ϸ� ����Ű�� ���� ��ü ���� ����

	float m_LocX;
	bool m_IsMoveRight;
	bool m_IsPlay;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly)
	TObjectPtr<class ASwitch> m_Switch;
};
