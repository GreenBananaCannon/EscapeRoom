//  Copyright Adam Tabis 2018

#pragma once

#include "CoreMinimal.h"
#include "DrawDebugHelpers.h"
#include "Components/InputComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


struct FGrabbedObjectVectors
{
	FVector StartLocation;
	FVector EndLocation;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:

	float Reach = 100.f; // how far ahead of the player can we reach

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	// Ray-cast and grab what is in reach
	void Grab();

	// call when grab is released
	void Release();
	
	// find attached physics component
	void FindPhysicsHandleComponent();

	// set up assumed attached input component
	void SetupInputComponent();

	// Return hit for first physics body in reach
	 FHitResult GetFirstPhysicsBodyInReach() const;

	 // return the view point info for current frame
	 FGrabbedObjectVectors GetGrabbedObjectVectors() const;

};
