#include "BTTask_FindpatrolPos.h"
#include "ABAIController.h"
#include "BehaviorTree/BlackboardComponent.h"    //블랙보드 쓰기위해서 헤더 참조
#include "NavigationSystem.h"    //네비게이션 쓰기위해서 헤더 참조


UBTTask_FindpatrolPos::UBTTask_FindpatrolPos()
{
    NodeName = TEXT("FindPatrolPos");    //FindPatrol의 노드의 이름을 FindPatrolPos로 정하겠다. 
}

EBTNodeResult::Type UBTTask_FindpatrolPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);    //부모함수 호출 (언리얼에서 만든 테스크 노드를 사용하겠다)

    auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
    if (nullptr == ControllingPawn)    //내가 점유한 폰이나 캐릭터가 없으면 
        return EBTNodeResult::Failed;    //노드실행을 실패로 반환하겠다.

    UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(ControllingPawn->GetWorld());

    if (nullptr == NavSystem)    //네비게이션 시스템이 없으면
        return EBTNodeResult::Failed;    //노드실행을 실패로 반환하겠다.

    FVector Origin = OwnerComp.GetBlackboardComponent()->GetValueAsVector(AABAIController::HomePosKey);    //내 원래 위치를 기억하고 있다.
    FNavLocation NextPatrol;    //다음 순찰위치

    if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.0f, NextPatrol))    //5M 이내에 순찰위치를 NextPatrol에 저장하겠다.
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsVector(AABAIController::PatrolPosKey, NextPatrol.Location);    //블랙보드키에 NextPatrol내용을 저장하겠다.
        return EBTNodeResult::Succeeded;//이과정이 마치면 성공을 반환
    }

    return EBTNodeResult::Failed;    //예외일 경우 실패를 반환 하겠다.
}