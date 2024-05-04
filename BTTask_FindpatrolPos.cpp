#include "BTTask_FindpatrolPos.h"
#include "ABAIController.h"
#include "BehaviorTree/BlackboardComponent.h"    //������ �������ؼ� ��� ����
#include "NavigationSystem.h"    //�׺���̼� �������ؼ� ��� ����


UBTTask_FindpatrolPos::UBTTask_FindpatrolPos()
{
    NodeName = TEXT("FindPatrolPos");    //FindPatrol�� ����� �̸��� FindPatrolPos�� ���ϰڴ�. 
}

EBTNodeResult::Type UBTTask_FindpatrolPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);    //�θ��Լ� ȣ�� (�𸮾󿡼� ���� �׽�ũ ��带 ����ϰڴ�)

    auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
    if (nullptr == ControllingPawn)    //���� ������ ���̳� ĳ���Ͱ� ������ 
        return EBTNodeResult::Failed;    //�������� ���з� ��ȯ�ϰڴ�.

    UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(ControllingPawn->GetWorld());

    if (nullptr == NavSystem)    //�׺���̼� �ý����� ������
        return EBTNodeResult::Failed;    //�������� ���з� ��ȯ�ϰڴ�.

    FVector Origin = OwnerComp.GetBlackboardComponent()->GetValueAsVector(AABAIController::HomePosKey);    //�� ���� ��ġ�� ����ϰ� �ִ�.
    FNavLocation NextPatrol;    //���� ������ġ

    if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.0f, NextPatrol))    //5M �̳��� ������ġ�� NextPatrol�� �����ϰڴ�.
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsVector(AABAIController::PatrolPosKey, NextPatrol.Location);    //������Ű�� NextPatrol������ �����ϰڴ�.
        return EBTNodeResult::Succeeded;//�̰����� ��ġ�� ������ ��ȯ
    }

    return EBTNodeResult::Failed;    //������ ��� ���и� ��ȯ �ϰڴ�.
}