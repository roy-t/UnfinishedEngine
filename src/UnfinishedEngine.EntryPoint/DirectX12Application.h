#pragma once

#include <DirectXMath.h>
using namespace DirectX;
using Microsoft::WRL::ComPtr;

class DirectX12Application
{
public:
	DirectX12Application(UINT width, UINT height, std::wstring assetPath);
	UINT GetWidth() const { return m_width; }
	UINT GetHeight() const { return m_height; }

	void OnInit();
	void OnUpdate();
	void OnRender();
	void OnDestroy();

private:
	static const UINT FrameCount = 2;

	struct Vertex
	{
		XMFLOAT3 position;
		XMFLOAT4 color;
	};

	// Pipeline objects.
	CD3DX12_VIEWPORT m_viewport;
	CD3DX12_RECT m_scissorRect;
	ComPtr<IDXGISwapChain3> m_swapChain;
	ComPtr<ID3D12Device> m_device;
	ComPtr<ID3D12Resource> m_renderTargets[FrameCount];
	ComPtr<ID3D12CommandAllocator> m_commandAllocator;
	ComPtr<ID3D12CommandQueue> m_commandQueue;
	ComPtr<ID3D12RootSignature> m_rootSignature;
	ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
	ComPtr<ID3D12PipelineState> m_pipelineState;
	ComPtr<ID3D12GraphicsCommandList> m_commandList;
	UINT m_rtvDescriptorSize;

	// App resources.
	ComPtr<ID3D12Resource> m_vertexBuffer;
	D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;

	// Synchronization objects.
	UINT m_frameIndex;
	HANDLE m_fenceEvent;
	ComPtr<ID3D12Fence> m_fence;
	UINT64 m_fenceValue;

	// Viewport
	UINT m_width;
	UINT m_height;
	float m_aspectRatio;

	// Adapter info
	bool m_useWarpDevice;
	
	// Root assets path.
	std::wstring m_assetsPath;

	void GetHardwareAdapter(
		_In_ IDXGIFactory1* pFactory,
		_Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter);

	void LoadPipeline();
	void LoadAssets();	
	void PopulateCommandList();
	void WaitForPreviousFrame();

	std::wstring GetAssetFullPath(LPCWSTR assetName);
};

