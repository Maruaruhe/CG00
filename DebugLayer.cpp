#include "DebugLayer.h"
void DebugLayer::Debug(){
	debugController = nullptr;
	if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)))) {
		debugController->EnableDebugLayer();
		debugController->SetEnableGPUBasedValidation(TRUE);
	}
}
void DebugLayer::Stop() {
	infoQueue = nullptr;
	if(SUCCEEDED())
}