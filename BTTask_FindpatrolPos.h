#pragma once

#include "EngineMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindpatrolPos.generated.h"

/**
 *
 */
UCLASS()
class UNREALCPP_0309_API UBTTask_FindpatrolPos : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UBTTask_FindpatrolPos();        //FindPatrolPos의 TaskNode의 생성자

    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwerComp,
        uint8* NodeMemory) override;    //TaskNode를 실행하는 함수를 상속받아서 재정의 
};