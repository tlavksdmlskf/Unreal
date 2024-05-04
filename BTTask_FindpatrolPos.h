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
    UBTTask_FindpatrolPos();        //FindPatrolPos�� TaskNode�� ������

    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwerComp,
        uint8* NodeMemory) override;    //TaskNode�� �����ϴ� �Լ��� ��ӹ޾Ƽ� ������ 
};