#pragma once
#include"ChiliWin.h"
#include "EngineException.h"
#include <d3d11.h>

class Graphics
{
public:
	class Exception : public EngineException
	{
		using EngineException::EngineException;
	};

	class HrException : public Exception {
	public:
		HrException(int line, const char*, HRESULT hr) noexcept;
		const char* what() const noexcept override;
		std::wstring& GetWhat() const noexcept;
		const char* GetType() const noexcept override;
		HRESULT GetErrorCode() const noexcept;
		std::wstring GetErrorString() const noexcept;
		std::wstring GetErrorDescription() const noexcept;
	private:
		HRESULT hr;
	};
	class DeviceRemovedException : public HrException
	{
		using HrException::HrException;
	public:
		const char* GetType() const noexcept override;
	};


	Graphics( HWND hWnd);
	Graphics(const Graphics&) = delete;
	Graphics& operator=(const Graphics&) = delete;
	~Graphics();
	void EndFrame();
	void ClearBuffer(float red, float green, float blue) noexcept;
private:
	ID3D11Device* pDevice = nullptr;
	IDXGISwapChain* pSwap = nullptr;
	ID3D11DeviceContext* pContext = nullptr;
	ID3D11RenderTargetView* pTarget = nullptr;
};
