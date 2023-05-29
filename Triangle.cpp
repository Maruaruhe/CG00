//#include "Triangle.h"
//
//void Triangle::Draw(/*Vector2* leftBot, Vector2* MiddleTop, Vector2* RightBot,*/ DirectX12* directX12){
//	MakeVertexResource(directX12);
//	MakeVertexBufferView();
//	DateResource(/*leftBot, MiddleTop, RightBot*/);
//	ViewportScissor();
//}
//
//void Triangle::MakeVertexResource(DirectX12* directX12) {
//	//VertexResourceを生成する--------------------------------------------------------------------------------
//	//頂点リソース用のヒープの作成の設定
//	uploadHeapProperties = {};
//	uploadHeapProperties.Type = D3D12_HEAP_TYPE_UPLOAD;
//	//頂点リソースの設定
//	vertexResourceDesc = {};
//	//バッファリソース。テクスチャの場合はまた別の設定をする
//	vertexResourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
//	vertexResourceDesc.Width = sizeof(Vector4) * 3;
//	//バッファの場合はこれらは１にする決まり
//	vertexResourceDesc.Height = 1;
//	vertexResourceDesc.DepthOrArraySize = 1;
//	vertexResourceDesc.MipLevels = 1;
//	vertexResourceDesc.SampleDesc.Count = 1;
//	//バッファの場合はこれにする決まり
//	vertexResourceDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
//	//実際に頂点リソースを作る
//	vertexResource = nullptr;
//	hr = directX12->GetDevice()->CreateCommittedResource(&uploadHeapProperties, D3D12_HEAP_FLAG_NONE, &vertexResourceDesc, D3D12_RESOURCE_STATE_GENERIC_READ, nullptr, IID_PPV_ARGS(&vertexResource));
//	assert(SUCCEEDED(hr));
//}
//void Triangle::MakeVertexBufferView() {
//	vertexBufferView = {};
//	vertexBufferView.BufferLocation = vertexResource->GetGPUVirtualAddress();
//	vertexBufferView.SizeInBytes = sizeof(Vector4) * 3;
//	vertexBufferView.StrideInBytes = sizeof(Vector4);
//}
//void Triangle::DateResource(/*Vector2* v1, Vector2* v2, Vector2* v3*/) {
//	/*v1->x = (v1->x - 640) / 640;
//	v2->x = (v2->x - 640) / 640;
//	v3->x = (v3->x - 640) / 640;
//
//	v1->y = (v1->y - 360) / 360;
//	v2->y = (v2->y - 360) / 360;
//	v3->y = (v3->y - 360) / 360;*/
//	vertexDate = nullptr;
//	vertexResource->Map(0, nullptr, reinterpret_cast<void**>(&vertexDate));
//	////LeftBottom
//	//vertexDate[0] = { v1->x,v1->y,0.0f,1.0f };
//	////MiddleTop
//	//vertexDate[1] = { v2->x,v2->y,0.0f,1.0f };
//	////RightBottom
//	//vertexDate[2] = { v3->x,v3->y,0.0f,1.0f };
//
//	vertexDate[0] = { -0.5f,-0.5f,0.0f,1.0f };
//	//MiddleTop
//	vertexDate[1] = { 0.0f,0.5f,0.0f,1.0f };
//	//RightBottom
//	vertexDate[2] = { 0.5f,-0.5f,0.0f,1.0f };
//}
//void Triangle::ViewportScissor() {
//	viewport = {};
//	viewport.Width = float(kClientWidth);
//	viewport.Height = float(kClientHeight);
//	viewport.TopLeftX = 0;
//	viewport.TopLeftY = 0;
//	viewport.MinDepth = 0.0f;
//	viewport.MaxDepth = 1.0f;
//
//	scissorRect = {};
//	scissorRect.left = 0;
//	scissorRect.right = kClientWidth;
//	scissorRect.top = 0;
//	scissorRect.bottom = kClientHeight;
//}
//void Triangle::AllReleasse() {
//	vertexResource->Release();
//}