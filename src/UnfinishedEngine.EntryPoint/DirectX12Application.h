#pragma once
class DirectX12Application
{
public:
	DirectX12Application(UINT width, UINT height);
	UINT GetWidth() const { return m_width; }
	UINT GetHeight() const { return m_height; }

	void OnInit();
	void OnUpdate();
	void OnRender();
	void OnDestroy();

private:
	void GetHardwareAdapter(
		_In_ IDXGIFactory1* pFactory,
		_Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter);

	// Viewport
	UINT m_width;
	UINT m_height;
	float m_aspectRatio;
};

