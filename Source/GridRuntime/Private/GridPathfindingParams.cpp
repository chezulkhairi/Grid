#include "GridPathfindingParams.h"
#include "GridManager.h"

FGridPathFindingRequest::FGridPathFindingRequest()
{
	bRemoveDest = false;
	MaxStep = -1;
	MaxFindStep = 5000;
}

UGridPathFinder::UGridPathFinder()
{

}

UGridPathFinder::~UGridPathFinder()
{
}

UGrid* UGridPathFinder::GetStartGrid()
{
	check(GridManager != nullptr);

	return GridManager->GetGridByPosition(Request.StartPos);
}

UGrid* UGridPathFinder::GetDestGrid()
{
	check(GridManager != nullptr);

	return GridManager->GetGridByPosition(Request.DestPos);
}

AActor* UGridPathFinder::GetSender()
{
	return Request.Sender;
}

bool UGridPathFinder::IsReachable_Implementation(UGrid* Start, UGrid* Dest)
{
	return !Dest->IsEmpty();
}
