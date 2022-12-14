#pragma once
#include <d3d11.h>

#include "TextureManager.h"

class SwapChain;
class DeviceContext;
class VertexBuffer;
class VertexShader;
class PixelShader;
class ConstantBuffer;
class IndexBuffer;
class RasterizerState;
class Texture;

class GraphicsEngine
{
public:
	GraphicsEngine();
	//Initialize the GraphicsEngine and DirectX 11 Device
	bool init();
	//Release all the resources loaded
	bool release();
	~GraphicsEngine();
public:
	static GraphicsEngine* get();
	TextureManager* getTextureManager();
public:
	SwapChain *createSwapChain();
	DeviceContext *getImmediateDeviceContext();
	VertexBuffer* createVertexBuffer();
	ConstantBuffer* createConstantBuffer();
	IndexBuffer* createIndexBuffer();
	VertexShader* createVertexShader(const void *shader_byte_code, size_t byte_code_size);
	PixelShader* createPixelShader(const void* shader_byte_code, size_t byte_code_size);
	RasterizerState* createRasterizer_state(bool wireframe);


public:

	bool compileVertexShader(const wchar_t* file_name, const char* entry_point_name, void** shader_byte_code, size_t* byte_code_size);
	bool compilePixelShader(const wchar_t* file_name, const char* entry_point_name, void** shader_byte_code, size_t* byte_code_size);

	void releaseCompiledShader();

	//bool createShaders();
	//bool setShaders();
	//void getShaderBufferAndSize(void** bytecode, UINT* size);

private:
	DeviceContext* m_imm_device_context;
	TextureManager* m_tex_manager = nullptr;
private:
	ID3D11Device* m_d3d_device;
	D3D_FEATURE_LEVEL m_feature_level;

private:
	IDXGIDevice* m_dxgi_device;
	IDXGIAdapter* m_dxgi_adapter;
	IDXGIFactory* m_dxgi_factory;
	ID3D11DeviceContext* m_imm_context;


private:
	ID3DBlob* m_blob = nullptr;

	ID3DBlob* m_vsblob = nullptr;
	ID3DBlob* m_psblob = nullptr;

	ID3D11VertexShader* m_vs = nullptr;
	ID3D11PixelShader* m_ps = nullptr;

	ID3D11RasterizerState* rasterizerState;

private:
	friend class SwapChain;
	friend class VertexBuffer;
	friend class VertexShader;
	friend class PixelShader;
	friend class ConstantBuffer;
	friend class IndexBuffer;
	friend class RasterizerState;
	friend class Texture;

};
